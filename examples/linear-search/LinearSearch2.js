class LinearSearch {
  static search(arr, callback) {
    for (let i = 0; i < arr.length; i++) {
      if (callback(arr[i])) {
        return i
      }
    }
    return -1
  }
}

const arr = [1, 2, 3, 6, 190, 4, 9]
const r1 = LinearSearch.search(arr, (item) => item === 5)
console.log(r1) // -1
const r2 = LinearSearch.search(arr, (item => item === 6))
console.log(r2) // 3

const arr2 = [{name: 'jack'}, {name: 'toy'}]
const r3 = LinearSearch.search(arr2, (item) => item.name === 'toy')
console.log(r3) // -1
