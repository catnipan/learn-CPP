// function hanoi(n, src, dst, tmp) {
//   if (n > 0) {
//     hanoi(n - 1, src, tmp, dst);
//     console.log(`move disk ${n} from ${src} to ${dst}`);
//     hanoi(n - 1, tmp, dst, src);
//   }
// }

const goUp = ({ n, src, dst, tmp }) => n > 1 && ({
  n: n - 1,
  src,
  dst: tmp,
  tmp: dst,
});

const goDown = ({ n, src, dst, tmp }) => n > 1 && ({
  n: n - 1,
  src: tmp,
  dst: dst,
  tmp: src,
});


function hanoi(n, src, dst, tmp) {
  const stack = [];
  let curr = { n, src, dst, tmp };
  while (true) {
    while (curr) {
      stack.push(curr);
      curr = goUp(curr);
    }
    if (stack.length === 0) {
      break;
    }
    const hn = stack.pop();
    console.log(`move disk ${hn.n} from ${hn.src} to ${hn.dst}`);
    curr = goDown(hn);
  }
}


hanoi(4, "A", "C", "B")