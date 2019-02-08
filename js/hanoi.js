function hanoi(n, src, dst, tmp) {
  if (n > 0) {
    hanoi(n - 1, src, tmp, dst);
    console.log(`move disk ${n} from ${src} to ${dst}`);
    hanoi(n - 1, tmp, dst, src);
  }
}

const top = ({n, src, dst, tmp}) => n > 1 && ({
  n: n - 1,
  src,
  dst: tmp,
  tmp: dst,
});

const down = ({n, src, dst, tmp}) => n > 1 && ({
  n: n - 1,
  src: tmp,
  dst: dst,
  tmp: src,
});

function* hanoiI(n, src, dst, tmp) {
  const stack = [];
  let curr = { n, src, dst, tmp };
  while (true) {
    while (curr) {
      stack.push(curr);
      curr = top(curr);
    }
    if (stack.length === 0) {
      break;
    }
    const hn = stack.pop();
    yield hn;
    curr = down(hn);
  }
}

// console.log(`move disk ${hn.n} from ${hn.src} to ${hn.dst}`);

// hanoi(3, 'A', 'B', 'C');
// console.log('----------');
const x = hanoiI(10, 'A', 'B', 'C');

while (true) {
  const { value: hn, done } = x.next();
  if (done) {
    break;
  }
  console.log(`move disk ${hn.n} from ${hn.src} to ${hn.dst}`);
}
