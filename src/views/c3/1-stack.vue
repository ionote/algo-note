<template>
  <div>
    <div>
      <ul>
        <li v-for="(s, i) in stack.getData().reverse()">{{s}}</li>
      </ul>
    </div>

    <div>栈顶元素: {{ stack.getTop() }}</div>
    <button @click="push">Push({{current}})</button>
    <button @click="pop">Pop</button>
  </div>
</template>

<script setup lang="ts">
// stack
// 线性存储
import {ref} from "vue";

class Stack {
  private data = []
  private top = 0 // top 永远指向空
  private maxSize = Infinity

  constructor(maxSize: number) {
    this.maxSize = maxSize
  }

  push(item) {
    // 检查栈溢出
    if (this.top === this.maxSize) return false

    this.data[this.top++] = item
    return true
  }

  pop() {
    // 检查是否有元素
    if (this.top === 0) return false

    return this.data[--this.top]
  }

  getTop() {
    // 检查是否有元素
    if (this.top === 0) return null

    return this.data[this.top - 1]
  }

  getData() {
    return this.data.slice(0, this.top)
  }
}

const stack = ref(new Stack(10))


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
