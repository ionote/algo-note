const MaxHeap = require('./MaxHeap')

class HeapSort {
  static sort(data) {
    const maxHeap = new MaxHeap()

    for (let i = 0; i < data.length; i++) {
      maxHeap.add(data[i])
    }

    for (let i = 0; i < data.length; i++) {
      data[i] = maxHeap.extractMax()
    }

    console.log(data)
    return data
  }
}

module.exports = HeapSort
