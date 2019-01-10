const doNothing = () => {};

const tree1 = {
  data: 'i',
  left: {
    data: 'd',
    left: {
      data: 'c',
      left: {
        data: 'a',
        left: undefined,
        right: {
          data: 'b',
          left: undefined,
          right: undefined,
        },
      },
      right: undefined,
    },
    right: {
      data: 'h',
      left: {
        data: 'f',
        left: {
          data: 'e',
          left: undefined,
          right: undefined,
        },
        right: {
          data: 'g',
          left: undefined,
          right: undefined,
        }
      },
      right: undefined,
    }
  },
  right: {
    data: 'l',
    left: {
      data: 'k',
      left: {
        data: 'j',
        left: undefined,
        right: undefined,
      },
      right: undefined,
    },
    right: {
      data: 'n',
      left: {
        data: 'm',
        left: undefined,
        right: undefined,
      },
      right: {
        data: 'p',
        left: {
          data: 'o',
          left: undefined,
          right: undefined,
        },
        right: undefined,
      }
    }
  }
}

const preOrderTraverseR = visit => tree => {
  if (!tree) return;
  visit(tree.data);
  preOrderTraverseR(visit)(tree.left);
  preOrderTraverseR(visit)(tree.right);
}

const preOrderTraverseI = (visit, log = doNothing) => tree => {
  const stack = [];
  let node = tree;
  while (true) {
    while (node) {
      visit(node.data);
      log('visit', node.data);
      if (node.right) {
        stack.push(node.right);
        log(stack.map(x => x.data));
      }
      node = node.left;
    }
    if (stack.length === 0) {
      break;
    }
    node = stack.pop();
    log(stack.map(x => x.data));
  }
}

const inOrderTraverseR = visit => tree => {
  if (!tree) return;
  inOrderTraverseR(visit)(tree.left);
  visit(tree.data);
  inOrderTraverseR(visit)(tree.right);
}

const inOrderTraverseI = (visit, log = doNothing) => tree => {
  const stack = [];
  let node = tree;
  while (true) {
    while (node) {
      stack.push(node);
      log(stack.map(x => x.data));
      node = node.left;
    }
    if (stack.length === 0) {
      break;
    }
    node = stack.pop();
    log(stack.map(x => x.data));
    log('visit ', node.data);
    visit(node.data);
    node = node.right;
  }
}

const postOrderTraverseR = visit => tree => {
  if (!tree) return;
  postOrderTraverseR(visit)(tree.left);
  postOrderTraverseR(visit)(tree.right);
  visit(tree.data);
}

const postOrderTraverseI = visit => tree => {
  let node = tree;
  const stack = [];

  const expand = (_node) => {
    let node = _node;
    stack.push([node, undefined]);
    while (node) {
      if (node.left) {
        stack.push([node.left, node.right]);
        node = node.left;
      } else if (node.right) {
        stack.push([node.right, undefined]);
        node = node.right;
      } else {
        break;
      }
    }
  }

  expand(node);

  while (true) {
    if (stack.length === 0) {
      break;
    }
    let [node, nodeCousin] = stack.pop();
    visit(node.data);
    if (nodeCousin) {
      expand(nodeCousin);
    }
  }
}

const levelOrderTraverseI = visit => tree => {
  const queue = [];
  let node = tree;
  queue.push(node);
  while (true) {
    if (queue.length === 0) {
      break;
    }
    node = queue.shift();
    visit(node.data);
    if (node.left) {
      queue.push(node.left);
    }
    if (node.right) {
      queue.push(node.right);
    }
  }
}

const toStringList = (traverse, log) => tree => {
  let str = "";
  traverse(data => {
    str += data;
  }, log)(tree);
  return str;
}

console.log(toStringList(preOrderTraverseR)(tree1));
console.log(toStringList(preOrderTraverseI)(tree1));
console.log(toStringList(inOrderTraverseR)(tree1));
console.log(toStringList(inOrderTraverseI)(tree1));
console.log(toStringList(postOrderTraverseR)(tree1));
console.log(toStringList(postOrderTraverseI)(tree1));
console.log(toStringList(levelOrderTraverseI)(tree1));