<template>
  <div>
    <div v-for="r in result">
      {{ r }}
    </div>
  </div>
</template>

<script setup>
// 节点
class Vertex {
  constructor(value, index) {
    this.value = value
    this.index = index
  }
}
// 邻接点
class AdjVertex {
  constructor(to, w, next) {
    this.to = to
    this.w = w
    this.next = next
  }
}
class Graph {
  constructor() {
    this.vertexes = []
    this.heads = [] // 这儿也可以直接用个二位数组进行存储
  }

  addVertex(v) {
    this.vertexes.push(new Vertex(v, this.vertexes.length))
  }

  hasEdge(u, v) {
    let heads = this.heads[u]
    let flag = false
    while (heads) {
      if (heads.to === v) {
        return true
      }
      heads = heads.next
    }
    return flag
  }

  addEdge(u, v, w) {
    // 如果有这条边, 则 return
    if (this.hasEdge(u, v)) {
      console.error(`已经存在边 ${u} -> ${v}`)
      return
    }
    const a1 = new AdjVertex(v, w, this.heads[u])
    this.heads[u] = a1
  }

  print() {
    const res = {}
    this.vertexes.forEach((v, i) => {
      res[i] = []
      res[i].push(v.value)
      res[i].push('-->')
      let p = this.heads[i]
      while (p) {
        // res[i].push(p)
        // res[i].push('-->')
        res[i].push(this.vertexes[p.to])
        res[i].push('-->')
        p = p.next
      }
    })
    console.log(res)
    return res
  }
}

const g = new Graph()

console.log(g)

g.addVertex(3) // 0
g.addVertex(5) // 1
g.addVertex(8) // 2
g.addVertex(4) // 3
g.addVertex(1) // 4
g.addEdge(0, 2, 10)
g.addEdge(0, 1, 10)
g.addEdge(0, 1, 10)
g.addEdge(3, 1, 10)
g.addEdge(3, 2, 10)
const result = g.print()
</script>
