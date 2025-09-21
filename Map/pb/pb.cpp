#include <bits/stdc++.h>
#define FILE_TYPE 0   // Constant representing a file node
#define DIR_TYPE 1    // Constant representing a directory node
using namespace std;
typedef long long LL;
const LL INF = LLONG_MAX;  // Infinity, not used directly but can represent unlimited quota

LL LD, LR, file_sz;  // Variables to store direct quota, descendant quota, and file size

// Node structure representing files and directories
struct node {
    unordered_map<string, node*> children; // Mapping of names to child nodes
    int type;      // Type of node: FILE_TYPE or DIR_TYPE
    LL ld, lr;     // Quotas for this directory: ld = direct size, lr = total including descendants
    LL sd, sr;     // Current sizes: sd = direct files, sr = total including descendants
    node(int t) : ld(0), lr(0), sd(0), sr(0), type(t) {} // Initialize sizes and type
};

string op, path_str;               // Operation type and path string from input
vector<string> path_segments;      // Segments of path split by '/'
node* root = new node(DIR_TYPE);   // Root directory of the filesystem

// Split path string into segments for easier traversal
void parse_path() {
    path_segments.push_back("/");  // Root is always the first segment
    stringstream ss(path_str);
    string s;
    while (getline(ss, s, '/')) if (!s.empty()) path_segments.push_back(s);
}

// Add a file or directory recursively
bool add(node* r, int u, int old_size) {
    bool end = u + 1 == path_segments.size(); // Check if this is the last segment (file)
    
    // Quota check: cannot add if it exceeds the parent directory's quota
    if (!end && r->lr && r->lr < r->sr + file_sz - old_size) return false;
    
    bool created = false; // Flag to indicate if a new node was created
    
    if (r->children[path_segments[u]]) { // Node already exists
        if (end && r->children[path_segments[u]]->type != FILE_TYPE) return false; // Can't overwrite a directory
        if (!end && r->children[path_segments[u]]->type != DIR_TYPE) return false; // Middle nodes must be directories
    } else if (end) {  // Create a new file at the end
        r->children[path_segments[u]] = new node(FILE_TYPE);
        created = true;
    } else {  // Create a new directory if middle node doesn't exist
        r->children[path_segments[u]] = new node(DIR_TYPE);
        created = true;
    }

    node* next = r->children[path_segments[u]];
    if (end) {  // Final segment: update sizes
        LL modify = file_sz - next->sr;  // Difference from old size
        
        // Check quota for direct and total sizes
        if ((r->ld && r->ld < r->sd + modify) || (r->lr && r->lr < r->sr + modify)) {
            if (created) r->children[path_segments[u]] = nullptr;  // Undo creation
            return false;
        }
        next->sr = file_sz; // Set file size
        r->sd += modify;    // Update parent direct size
        r->sr += modify;    // Update parent total size
        return true;
    }

    // Recurse for next segment (directory)
    if (add(next, u + 1, old_size)) {
        r->sr += file_sz - old_size; // Update total size after successful addition
        return true;
    }

    // Cleanup if addition failed
    if (created) r->children[path_segments[u]] = nullptr;
    return false;
}

// Delete a file or directory recursively
LL del(node* r, int u) {
    if (r->children[path_segments[u]] == nullptr) return 0; // Node doesn't exist
    bool end = u + 1 == path_segments.size(); // Check if last segment
    if (!end && r->children[path_segments[u]]->type != DIR_TYPE) return 0; // Invalid path
    
    if (end) {  // Delete file
        LL res = r->children[path_segments[u]]->sr;  // Size to subtract
        if (r->children[path_segments[u]]->type == FILE_TYPE) r->sd -= res; // Update direct size
        r->children[path_segments[u]] = nullptr;  // Remove node
        r->sr -= res;  // Update total size
        return res;
    }

    // Recursively delete from subdirectories
    LL res = del(r->children[path_segments[u]], u + 1);
    r->sr -= res;  // Update total size
    return res;
}

// Reset quotas for a directory
bool reset(node* r, int u) {
    if (r->children[path_segments[u]] == nullptr) return false; // Node must exist
    bool end = u + 1 == path_segments.size(); // Last segment?
    if (!end && r->children[path_segments[u]]->type != DIR_TYPE) return false; // Middle nodes must be directories

    node* next = r->children[path_segments[u]];
    if (end) {  // Target directory
        if (next->type != DIR_TYPE) return false; // Must be directory
        if ((LD && LD < next->sd) || (LR && LR < next->sr)) return false; // Quota too small
        next->ld = LD; // Set direct quota
        next->lr = LR; // Set total quota
        return true;
    }
    return reset(next, u + 1); // Recurse
}

// Get the size of a file
LL get_size(node* r, int u) {
    bool end = u + 1 == path_segments.size(); // Last segment?
    if (r->children[path_segments[u]] == nullptr) return 0; // Not exist
    if (!end && r->children[path_segments[u]]->type != DIR_TYPE) return 0; // Invalid path
    if (end && r->children[path_segments[u]]->type != FILE_TYPE) return 0; // Not a file
    return end ? r->children[path_segments[u]]->sr : get_size(r->children[path_segments[u]], u + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    root->children["/"] = new node(DIR_TYPE); // Initialize root directory

    int T;
    cin >> T;  // Number of operations
    while (T--) {
        cin >> op >> path_str; // Read operation and path
        path_segments.clear();
        parse_path(); // Split path into segments
        
        if (op == "C") {  // Create file
            cin >> file_sz;
            if (add(root, 0, get_size(root, 0))) cout << "Y\n"; // Success
            else cout << "N\n"; // Failed
        } else if (op == "R") { // Remove file/directory
            del(root, 0);
            cout << "Y\n";
        } else {  // Reset quotas
            cin >> LD >> LR;
            if (reset(root, 0)) cout << "Y\n"; // Success
            else cout << "N\n"; // Failed
        }
    }
    return 0;
}
