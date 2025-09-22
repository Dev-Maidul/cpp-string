const createCounter = () => {
  let count = 0;

  return {
    increment: () => {
      count++;
      console.log(`Current count: ${count}`);
    },

    decrement: () => {
      count--;
      console.log(`Current count: ${count}`);
    },

    reset: () => {
      count = 0;
      console.log(`Count has been reset to: ${count}`);
    },

    getCount: () => {
      return count;
    }
  };
};

const myCounter = createCounter();

console.log('--- Initial State ---');
console.log(myCounter.getCount());

console.log('\n--- Incrementing the count ---');
myCounter.increment();
myCounter.increment();
myCounter.increment();

console.log('\n--- Checking the current count ---');
console.log(`The count is now: ${myCounter.getCount()}`);

console.log('\n--- Decrementing the count ---');
myCounter.decrement();

console.log('\n--- Resetting the count ---');
myCounter.reset();