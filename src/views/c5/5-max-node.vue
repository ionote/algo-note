<template>
  <div>
    <div v-for="r in result">
      {{ r }}
    </div>
  </div>
</template>

<script setup>
class Graph {
  edges = []
  heads = []
  vertexes = []
  vertexMap = {}

  addVertex(v) {
    const index = this.vertexes.length
    this.vertexes.push({
      value: v,
      index,
    })
    this.vertexMap[v] = index
    this.heads[index] = -1
  }

  addEdge(u, v, w = 0) {
    if (!this.vertexes[u] || !this.vertexes[v]) {
      console.error(`不存在节点 ${u} 或 ${v}`)
      return
    }

    const next = this.heads[v]
    const edge = {
      to: u,
      from: v,
      w,
      next: next ?? -1,
    }
    this.edges.push(edge)
    this.heads[v] = this.edges.length - 1
  }

  print() {
    const res = []
    console.log(this.vertexes, this.heads, this.edges)
    this.vertexes.forEach((v, i) => {
      res[i] = [i, '=', v, ' --> ']
      let next = this.heads[i]
      while (next !== -1) {
        res[i].push(next)
        res[i].push(this.edges[next])
        res[i].push(' --> ')
        next = this.edges[next].next
      }
    })
    return res
  }

  setMax() {
    // 从最大的节点开始遍历
    for (let i = this.vertexes.length - 1; i >= 0; i--) {
      // bfs
      this.bfs(i, (v) => {
        if (v.max) {
          return
        }
        v.max = this.vertexes[i].value
      })
    }

    // 输出 max
    let maxString = `最大值：`
    this.vertexes.forEach((v) => {
      maxString += v.max + '-->'
    })
    console.log(maxString)
  }

  bfs(u = 0, callback = () => {}) {
    const visited = {}
    const queue = [this.vertexes[u]]
    while (queue.length) {
      const cur = queue.shift()

      if (!visited[cur.index]) {
        console.log(`访问到了`, cur)
        callback(cur)
        visited[cur.index] = true
      }

      // 遍历所有的邻接点
      let next = this.heads[cur.index]
      while (next !== -1) {
        const edge = this.edges[next]
        const to = edge.to
        const toVertex = this.vertexes[to]
        if (!visited[toVertex.index]) {
          queue.push(toVertex)
        }
        next = edge.next
      }
    }
  }
}
const g = new Graph()
for (let i = 1; i <= 4; i++) {
  g.addVertex(i)
}
g.addEdge(0, 1)
g.addEdge(1, 3)
g.addEdge(3, 2)

const result = g.print()

g.setMax()
</script>
