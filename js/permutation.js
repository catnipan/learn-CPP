function* permutationR(A) {
  const len = A.length;

  function* permu(s) {
    if (s === len) {
      yield A;
      return;
    }
    for (let i = s; i < len; i++) {
      [A[s], A[i]] = [A[i], A[s]];
      yield* permu(s + 1);
      [A[s], A[i]] = [A[i], A[s]];
    }
  }
  yield* permu(0);
}

class Node {
  constructor(base, target) {
    this.base = base;
    this.target = target;
  }
  isValid(max) {
    return (this.base < max && this.target < max);
  }
  swap(array) {
    [array[this.base], array[this.target]] = [array[this.target], array[this.base]];
  }
  getFirstChild() {
    return new Node(this.i+base, this.i+target);
  }
  getCousin() {
    return new Node(this.base, this.target+1);
  }
}

const A = [];
for (let i = 1; i <= 3; i++) {
  A.push(i);
}

function* permutationI(A) {
  const len = A.length;

  const stack = [];
  let curr = new Node(0,0);
  while (true) {

    while (curr.isValid(len)) {
      curr.swap(A);
      stack.push(curr);
      curr = curr.getFirstChild();
    }

    yield A; // now is the deepest node

    // find cousin, which is next node for curr
    while (true) {
      if (stack.length === 0) {
        return;
      }
      const node = stack.pop();
      node.swap(A); // need to visit when backtrack
      const cousin = node.getCousin();
      if (cousin.isValid(len)) {
        curr = cousin;
        break;
      }
    }
  }
}

for (var permu of permutationR(['a','b','c'])) {
  console.log(permu);
}