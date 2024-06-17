<template>
  <div>
    <div>
      <ul>
        <li v-for="(s, i) in stack.getData()">{{ s }}</li>
      </ul>
    </div>

    <div>栈顶元素: {{ stack.getTop() }}</div>
    <button @click="push">Push({{ current }})</button>
    <button @click="pop">Pop</button>
  </div>
</template>

<script setup lang="ts">
// stack
// 线性存储
import {ref} from "vue";

class LinkNode {
  public data: any
  public next: LinkNode

  constructor(data, next) {
    this.data = data
    this.next = next
  }
}

class LinkStack {
  private top = null
  private maxSize = Infinity
  private size = 0

  constructor(maxSize: number) {
    this.maxSize = maxSize
  }

  push(item) {
    // 检查栈溢出
    if (this.size === this.maxSize) return false

    // 创建一个节点
    const linkNode = new LinkNode(item, this.top)
    this.top = linkNode
    this.size++
    return true
  }

  pop() {
    // 检查是否有元素
    if (this.size === 0) return false
    const top = this.top
    this.top = top.next
    this.size--
    return top.data
  }

  getTop() {
    // 检查是否有元素
    if (this.size === 0) return null

    return this.top.data
  }

  getData() {
    let t = this.top
    const data = []
    while (t) {
      data.push(t.data)
      t = t.next
    }
    return data
  }
}

const stack = ref(new LinkStack(10))


function random() {
  return Math.floor(Math.random() * 10 + 10)
}

const current = ref(random())

function push() {
  stack.value.push(current.value)
  current.value = random()
}

function pop() {
  stack.value.pop()
}
</script>
