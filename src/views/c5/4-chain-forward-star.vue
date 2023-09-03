<template>
  <div>
    <div v-for="r in result">
      {{ r }}
    </div>
  </div>
</template>

<script setup lang="ts">
class Vertex {
  value: any
  index: number
  constructor(value: any, index) {
    this.value = value
    this.index = index
  }
}

class Edge {
  from: Vertex
  to: Vertex
  w: number
  next: number
  prev: number
  head: number
  constructor(from, to, w, prev, next, head) {
    this.from = from
    this.to = to
    this.w = w
    this.prev = prev
    this.next = next
    this.head = head
  }
}

class Graph {
  edges: Edge[]
  vertexes: Vertex[]
  heads: number[]
  constructor() {
    this.edges = []
    this.vertexes = []
    this.heads = []
  }

  addEdge(u, v, w = 0) {
    const next = this.heads[u]
    console.log(`next`, this.heads[u])
    const edge = new Edge(this.vertexes[u], this.vertexes[v], w, -1, next, u)
    this.edges.push(edge)
    this.heads[u] = this.edges.length - 1
    if (this.edges[next]) {
      this.edges[next].prev = this.heads[u]
    }
    console.log(this.heads[u], u)
  }

  addVertex(v) {
    this.vertexes.push(new Vertex(v, this.vertexes.length))
    this.heads.push(-1)
  }

  delEdge(i) {
    if (!this.edges[i]) {
      console.error(`没有找到边${i}`)
      return
    }
    // 找到该边的前驱边
    const prev = this.edges[i].prev
    const next = this.edges[i].next
    if (prev !== -1) {
      this.edges[prev].next = this.edges[i].next
    } else {
      // 是个节点
      const head = this.edges[i].head
      this.heads[head] = next
    }
  }

  // 删除点
  delVertext(i) {
    // 找到所有指向该节点的边, 删除
    this.edges.forEach((edge) => {
      if (edge.from?.index === i || edge.to?.index === i) {
        this.delEdge(i)
      }
    })
    // 删除掉涉及的点
    this.vertexes[i] = -1
    this.heads[i] = -1
  }

  print() {}
}

const g = new Graph()
g.addVertex(1)
g.addVertex(2)
g.addVertex(3)
g.addVertex(5)
g.addVertex(6)
g.addVertex(4)
g.addVertex(7)
g.addEdge(0, 1)
g.addEdge(1, 2)
g.addEdge(2, 3)
g.addEdge(3, 4)
g.addEdge(4, 5)
g.addEdge(5, 0)
g.addEdge(3, 6)

console.log(g)

// 查找 2 的临边
console.log(g.edges[g.heads[2]])
console.log(g)
// 删除边 0
// g.delEdge(0)

// 删除点 0
g.delVertext(0)

const result = []
</script>
