const MaxHeap = require('./MaxHeap')
const HeapSort = require('./HeapSort')
const test = {
  maxHeap() {
    const m = new MaxHeap()
    const j = 1000
    for (let i = 0; i < j; i++) {
      m.add(Math.random() * 100)
    }

    let arr = []
    while (!m.isEmpty()) {
      const max = m.extractMax()
      arr.push(max)
    }

    for (let i = 0; i < j - 1; i++) {
      if (arr[i] < arr[i + 1]) {
        throw new Error(`出错了`)
      }
    }

    console.log(`完成了`)
  },
  heapSort() {
    const arr = [1, 4, 19, 5, 8, 22]
    HeapSort.sort(arr)
  },
  heapify() {
    const arr = [1, 4, 19, 5, 8, 22]
    const m = new MaxHeap(arr)
    console.log(m)
  },
}

test.maxHeap()
test.heapSort()
test.heapify()
