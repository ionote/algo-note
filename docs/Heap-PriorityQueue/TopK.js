const PriorityQueue = require('./PriorityQueue')

class TopK {
  // 获取最小的 k 个元素
  static getLeastNumber(arr, k) {
    const pq = new PriorityQueue()

    for (let i = 0; i < k; i++) {
      pq.enqueue(arr[i])
    }

    for (let i = k; i < arr.length; i++) {
      if (!pq.isEmpty() && arr[i] < pq.getFront()) {
        pq.dequeue()
        pq.enqueue(arr[i])
      }
    }

    const ret = []
    const len = pq.getSize()
    for (let i = 0; i < len; i++) {
      ret.push(pq.dequeue())
    }
    console.log(ret)
    return ret
  }
}

const arr = [1, 5, 10, 9, 22, 77, 44, 55, 9, 7, 4, 8]

TopK.getLeastNumber(arr, 5)
