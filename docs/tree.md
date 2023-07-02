# 树

## 树的概念

- 深度
- 高度
- 节点的度：节点的子树个数

## 树的种类

- 二叉树
- 满二叉树
- 完全二叉树

![](imgs/2023-07-02-12-51-32.png)

## 二叉树的性质

- 非空二叉树第i层上的节点数最多为2^(i-1)
- 深度为k的二叉树至多有2^k-1个节点
- 完全二叉树，父节点i，左子节点2i，右子节点2i+1

## 二叉树遍历

![](imgs/2023-07-02-12-54-29.png)


### 深度优先遍历

遍历时，先往下遍历，遍历到最后一个节点，再往上遍历。

![](imgs/2023-07-02-13-10-02.png)

递归遍历，递归只想一层。

- 前序遍历 Pre-order：根 左子树 右子树
  - A BDHIEJ CFG
- 中序遍历 In-order：左子树 根 右子树
  - HDIBJE A FCG
- 后序遍历 Post-order：左子树 右子树 根
  - HIDJEB FGC A

### 广度优先遍历

- 层遍历，借助队列
  - A BC DEFG HIJ

![](imgs/2023-07-02-13-11-55.png)

![](imgs/2023-07-02-13-13-40.png)

## 实战题目

- [二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)
- [N叉树的前序遍历](https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/)
- [N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)
- [二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
