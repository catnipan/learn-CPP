function partition(arr, from, to) {
  const p = Math.floor((to - from) * Math.random() + from);

  [arr[to - 1], arr[p]] = [arr[p], arr[to - 1]]
  let l = 0;
  for (let i = 0; i < to - 1; i++) {
    if (arr[i] <= arr[to - 1]) {
      [arr[l], arr[i]] = [arr[i], arr[l]]
      l++;
    }
  }
  [arr[to - 1], arr[l]] = [arr[l], arr[to - 1]]

  return l;
}

function _quickSort(arr, from, to) {
  if (to - from < 2) return;
  
  const l = partition(arr, from, to);
  _quickSort(arr, from, l);
  _quickSort(arr, l+1, to);
}

function quickSort(arr) {
  _quickSort(arr, 0, arr.length);
}

function SortNode(from, to) {
  this.from = from;
  this.to = to;
}
SortNode.prototype.getChildren = function(l) {
  return [new SortNode(this.from, l), new SortNode(l+1, this.to)];
}
SortNode.prototype.isValid = function() {
  return (this.to - this.from >= 2);
}

function quickSortI(arr) {
  const stack = [];
  let curr = new SortNode(0, arr.length);
  while (true) {
    while (curr.isValid()) {
      const l = partition(arr, curr.from, curr.to);
      const [upChild, downChild] = curr.getChildren(l);
      curr = upChild;
      stack.push(downChild);
    }
    if (stack.length === 0) {
      break;
    }
    curr = stack.pop();
  }
}

const arr1 = [20,22,2,3,2,3,4,5,67,8,8,7,6,6,3,56,19,5,6,7,9,10];
quickSort(arr1);
console.log(arr1);

const arr2 = [20,22,2,3,2,3,4,5,67,8,8,7,6,6,3,56,19,5,6,7,9,10];
quickSortI(arr2);
console.log(arr2);