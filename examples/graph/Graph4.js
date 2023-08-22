// 链式前向星
class Graph {
  constructor() {
    this.vertices = []
    this.edges = []
  }

  addVertex(v) {
    const vertex = new Vertex(v)
    this.vertices.push(vertex)
  }

  addEdge(i, j) {
    this.edges.push([i, j])
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

g1.addVertex(3)
g1.addVertex(5)
g1.addVertex(8)
g1.addEdge(0, 2)
g1.addEdge(2, 1)
console.log(g1)
