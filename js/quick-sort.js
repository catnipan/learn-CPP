function _quickSort(arr, from, to) {
  if (to - from < 2) return;
  const p = from + Math.floor((to - from) / 2);

  // partition
  [arr[to - 1], arr[p]] = [arr[p], arr[to - 1]]
  let l = 0;
  for (let i = 0; i < to - 1; i++) {
    if (arr[i] <= arr[to - 1]) {
      [arr[l], arr[i]] = [arr[i], arr[l]]
      l++;
    }
  }
  [arr[to - 1], arr[l]] = [arr[l], arr[to - 1]]

  // recursive sort both part
  _quickSort(arr, 0, l);
  _quickSort(arr, l+1, to);
}

function quickSort(arr) {
  _quickSort(arr, 0, arr.length);
}

const arr1 = [20,2,3,56,19,5,6,7,9,10];
quickSort(arr1);
console.log(arr1);