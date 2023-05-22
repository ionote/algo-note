class LinearSearch {
  static search(arr, item) {
    for (let i = 0; i < arr.length; i++) {
      if (arr[i] === item) {
        return i
      }
    }
    return -1
  }
}

const arr = [1, 2, 3, 6, 190, 4, 9]
const r1 = LinearSearch.search(arr, 5)
console.log(r1) // -1
const r2 = LinearSearch.search(arr, 6)
console.log(r2) // 3
