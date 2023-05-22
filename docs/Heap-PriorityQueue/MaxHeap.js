class MaxHeap {
  constructor(data = []) {
    this.data = data
    this.heapify()
  }

  size() {
    return this.data.length
  }

  isEmpty() {
    return !this.data.length
  }

  parent(index) {
    if (index === 0) {
      throw new Error(`index-0 doesn't have parent.`)
    }
    return Math.floor((index - 1) / 2)
    // 1 -> 0, 2 -> 0, 从 0 开始
  }

  leftChild(index) {
    return index * 2 + 1
  }

  rightChild(index) {
    return index * 2 + 2
  }

  // 添加元素
  add(e) {
    this.data.push(e)
    this.siftUp(this.data.length - 1)
  }

  // 上浮
  siftUp(k) {
    while (k > 0 && this.data[this.parent(k)] < this.data[k]) {
      this.swap(k, this.parent(k))
      k = this.parent(k)
    }
  }

  findMax() {
    if (this.isEmpty()) {
      throw new Error(`Can not findMax when heap is Empty`)
    }
    return this.data[0]
  }

  // 取出堆中最大元素
  extractMax() {
    const ret = this.findMax()
    // 如果只有一个元素，直接 pop 返回
    // if (this.data.length === 1) {
    //   this.data.pop()
    //   return ret
    // }

    // 如果有多个元素，将最后一个元素移动到第一个元素
    // this.data[0] = this.data.pop()
    this.swap(0, this.data.length - 1)
    this.data.pop()

    this.siftDown(0)
    return ret
  }

  siftDown(k) {
    // 下沉到左节点超出 size() 肯定是没有节点了
    while (this.leftChild(k) < this.size()) {
      let j = this.leftChild(k)

      // 如果有 rightChild, 并且 rightChild > leftChild
      if (j + 1 < this.size() && this.data[j + 1] > this.data[j]) {
        j = this.rightChild(k)
      }
      // data[j] 是 leftChild 和 rightChild 中的最大值

      if (this.data[k] > this.data[j]) {
        break
      }

      this.swap(k, j)
      k = j
    }
  }

  swap(i, j) {
    if (i < 0 || i >= this.size() || j < 0 || j >= this.size()) {
      throw new Error(`Index is illegal`)
    }
    const tmp = this.data[i]
    this.data[i] = this.data[j]
    this.data[j] = tmp
  }

  replace(e) {
    const ret = this.findMax()
    this.data[0] = e
    this.siftDown(0)
    return ret
  }

  heapify() {
    for (let i = this.parent(this.data.length - 1); i >= 0; i--) {
      this.siftDown(i)
    }
  }
}

module.exports = MaxHeap
