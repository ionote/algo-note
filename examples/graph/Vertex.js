export class Vertex {
  static index = 0
  constructor(value) {
    this.index = Vertex.index++
    this.value = value
  }
}
