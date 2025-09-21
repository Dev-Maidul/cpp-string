#include <bits/stdc++.h>
#define  FILE 0
#define  DIRE 1
using namespace std;
typedef long long LL;
const LL INF = LLONG_MAX;
LL LD, LR, file_sz;  
struct node {
    unordered_map<string, node*> dir;
    int type;
    LL ld, lr, sd, sr;
    node(int t) :ld(0), lr(0), sd(0), sr(0), type(t) {}
};

string op, pa;
vector<string> path;
node* root = new node(DIRE);
void prase() {
    path.push_back("/");
    stringstream ss(pa);
    string s;
    while (getline(ss, s, '/')) if (!s.empty()) path.push_back(s);
}

bool add(node* r, int u, int old_size) {
    bool end = u + 1 == path.size();
    if (!end && r->lr &&  r->lr < r->sr + file_sz - old_size) return false;
    bool hc = false;        // 记录本次递归是否创建了新节点，若操作失败需要回溯删除！！！！！！！！！！！！！！！！！！！！
    if (r->dir[path[u]]) {      // 目录或文件存在
        if (end && r->dir[path[u]]->type != FILE) return false;
        if (!end && r->dir[path[u]]->type != DIRE) return false;
    } else if (end) {        // 创建文件
        r->dir[path[u]] = new node(FILE);
        hc = true;
    } else {
        r->dir[path[u]] = new node(DIRE);
        hc = true;
    }

    node* next = r->dir[path[u]];
    if (end) {
        LL modify = file_sz - next->sr;
        if ((r->ld && r->ld < r->sd + modify) || (r->lr && r->lr < r->sr + modify)) {
            if (hc) r->dir[path[u]] = nullptr;      // ！！！！！！！！！
            return false;
        }
        next->sr = file_sz;     // 若是文件的话，使用sr存储文件的大小
        r->sd += modify;
        r->sr += modify;
        return true;
    }
    if (add(next, u + 1, old_size)) {
        r->sr += file_sz - old_size;
        return true;
    }
    if (hc)r->dir[path[u]] = nullptr;       // ！！！！！！！
    return false;
}
// 若该路径所指的文件不存在，则不进行任何操作
// 若该路径所指的文件是目录，则移除该目录及其所有后代文件。
LL del(node* r, int u) {            // 返回所删除的长度，以便回溯进行sr的修改
    if (r->dir[path[u]] == nullptr) return 0;
    bool end = u + 1 == path.size();
    if (!end && r->dir[path[u]]->type != DIRE) return 0;
    if (end) {
        LL res = r->dir[path[u]]->sr;
        if (r->dir[path[u]]->type == FILE) r->sd -= res;        // 若删的是文件，对sd也有影响!!!!!!!
        r->dir[path[u]] = nullptr;
        r->sr -= res;
        return res;
    }
    LL res = del(r->dir[path[u]], u + 1);
    r->sr -= res;
    return res;
}

//若路径所指的文件不存在，或者不是目录文件，则该指令执行不成功。
// 若在该目录上已经设置了配额，则将原配额值替换为指定的配额值。
//若在应用新的配额值后，该文件系统配额变为不满足，那么该指令执行不成功。
bool reset(node* r, int u) {
    if (r->dir[path[u]] == nullptr) return false;       // 文件不存在
    bool end = u + 1 == path.size();
    if (!end && r->dir[path[u]]->type != DIRE) return false;        // 走的是目录文件，却遇到普通文件
    node* next = r->dir[path[u]];
    if (end) {
        if (next->type != DIRE) return false;
        if ((LD && LD < next->sd) || (LR && LR < next->sr)) return false;
        next->ld = LD;
        next->lr = LR;
        return true;
    }
    return reset(next, u + 1);
}
LL get_size(node* r,int u) {
    bool end = u + 1 == path.size();
    if (r->dir[path[u]] == nullptr) return 0;
    if (!end && r->dir[path[u]]->type != DIRE) return 0;
    if (end && r->dir[path[u]]->type != FILE) return 0;
    if (end) return r->dir[path[u]]->sr;
    return get_size(r->dir[path[u]], u + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    root->dir["/"] = new node(DIRE);
    int T;
    cin >> T;
    while (T--) {
        cin >> op >> pa;
        path.clear();
        prase();
      
        if (op == "C") {
            cin >> file_sz;
            if (add(root, 0, get_size(root,0))) cout << "Y\n";
            else cout << "N\n";
        } else if (op == "R") {
            del(root, 0);
            cout << "Y\n";
        } else {
            cin >> LD >> LR;
            if (reset(root, 0)) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}