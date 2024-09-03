import 'regenerator-runtime/runtime'
import App from './components/App.vue'
import store from './store'

const appInfo = {
  name: 'Hello',
  id: 'hello',
  icon: 'info',
  isFileEditor: false,
  extensions: []
}

const routes = [
  {
    name: 'hello',
    path: '/',
    components: {
      app: App
    }
  }
]

const navItems = [
  {
    name: 'Hello',
    iconMaterial: appInfo.icon,
    route: {
      name: 'hello',
      path: `/${appInfo.id}/`
    }
  }
]

export default {
  appInfo,
  store,
  routes,
  navItems
}
