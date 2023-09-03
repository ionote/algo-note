<template>
  <div></div>
</template>

<script setup>
// 无向图的邻接矩阵表示
class Graph {
  constructor() {
    this.vertices = []
    this.edges = []
  }

  addVertex(v) {
    const vertex = new Vertex(v)
    this.vertices.push(vertex)

    const j = this.vertices.length - 1
    for (let i = 0; i < this.vertices.length; i++) {
      if (!this.edges[i]) {
        this.edges[i] = []
      }
      this.edges[i][j] = 0
    }
    this.edges[j] = this.vertices.map(() => 0)

    return j
  }

  addEdge(u, v) {
    // 找到下标
    const i = this.findVertexIndex(u)
    const j = this.findVertexIndex(v)

    // 无向图
    this.edges[i][j] = 1
    this.edges[j][i] = 1
  }

  findVertexIndex(v) {
    for (let i = 0; i < this.vertices.length; i++) {
      if (v === this.vertices[i].value) {
        return i
      }
    }
    return -1
  }

  bfs() {
    const queue = [this.vertices[0]]
    const visited = {}

    while (queue.length) {
      const cur = queue.shift()
      console.log(`访问到了`, cur)

      visited[cur.index] = true
      // 查找所有的邻接点
      for (let i = 0; i < this.edges[cur.index].length; i++) {
        if (this.edges[cur.index][i] === 1 && !visited[i]) {
          queue.push(this.vertices[i])
        }
      }
    }

    this.vertices.forEach((v) => {
      if (!visited[v.index]) {
        console.log(`没有访问到的点`, v)
      }
    })
  }

  dfs() {
    const visited = {}
    const _dfs = (v) => {
      console.log(`访问到了`, v)
      visited[v.index] = true

      for (let i = 0; i < this.edges[v.index].length; i++) {
        if (this.edges[v.index][i] === 1 && !visited[i]) {
          _dfs(this.vertices[i])
        }
      }
    }

    _dfs(this.vertices[0])
  }
}

class Vertex {
  static index = 0
  constructor(value) {
    this.index = Vertex.index++
    this.value = value
  }
}

const g1 = new Graph()

// 添加顶点信息
const arr = ['a', 'b', 'c', 'd']

arr.forEach((v) => g1.addVertex(v))

// 添加边
g1.addEdge('a', 'c') //  这里增加的是顶点
g1.addEdge('c', 'b')
g1.addEdge('c', 'd')
console.log(g1)

// g1.bfs()
g1.dfs()
</script>
