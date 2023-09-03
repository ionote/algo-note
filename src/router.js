import * as VueRouter from 'vue-router'

export default VueRouter.createRouter({
  history: VueRouter.createWebHashHistory(),
  routes: [
    {
      path: '/',
      redirect: '/c1',
    },
    {
      path: '/c1',
      name: '面向对象和UML类图',
      component: () => import('./views/c1/Index.vue'),
    },
    {
      path: '/c5-1',
      name: '邻接矩阵',
      component: () => import('./views/c5-1/Index.vue'),
    },
    {
      path: '/c5-2',
      name: '边集数组',
      component: () => import('./views/c5-2/Index.vue'),
    },
    {
      path: '/c5-3',
      name: '邻接表',
      component: () => import('./views/c5-3/Index.vue'),
    },
    {
      path: '/c5-4',
      name: '链式前向星',
      component: () => import('./views/c5-4/Index.vue'),
    },
    {
      path: '/c5-5',
      name: '链式前向星',
      component: () => import('./views/c5-4/Index.vue'),
    },
  ],
})
