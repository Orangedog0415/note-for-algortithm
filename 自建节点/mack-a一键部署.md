# mack-a / v2ray-agent 一键部署教程

## 一、准备工作

需要先准备好：

1. 一台 VPS
2. 能 SSH 登录 VPS
3. VPS 系统建议使用 Debian / Ubuntu
4. 使用 root 用户操作，或者具备 sudo 权限

> 注意：请遵守当地法律法规，仅用于学习和合规网络访问。

---

## 二、安装脚本

SSH 登录 VPS 后，执行下面命令：

```bash
wget -P /root -N --no-check-certificate "https://raw.githubusercontent.com/mack-a/v2ray-agent/master/install.sh" && chmod 700 /root/install.sh && /root/install.sh
```

安装完成后，后续可以通过下面命令启动脚本：

```bash
vasma
```

---

## 三、部署 Reality 节点

输入：

```bash
vasma
```

进入菜单后按下面步骤选择：

1. 选择 `3. 一键无域名安装 Reality`
2. 伪装域名选择类似微软这类国外常见域名
   推荐填写：

```text
www.microsoft.com
```

3. 内核选择：

```text
1. Xray-core
```

4. 端口设置为：

```text
443
```

5. 按脚本提示继续完成安装

安装完成后，脚本会生成节点信息，一般会有 `vless://` 开头的链接。
请保存好这个链接，后面导入客户端要用。

---

## 四、安装 BBR 加速

再次输入：

```bash
vasma
```

进入菜单后：

1. 选择 `18. 安装 BBR / DD 脚本`
2. 选择：

```text
11. BBR + FQ
```

安装完成后，执行重启：

```bash
reboot
```

VPS 重启后，重新 SSH 登录即可。

---

## 五、VLESS 转 Clash 订阅

脚本生成的节点一般是 `vless://` 开头的链接。

Clash 客户端通常需要 Clash 格式订阅，所以需要把 `vless://` 链接转换成 Clash 配置或订阅。

操作方法：

1. 复制安装完成后生成的 `vless://` 节点链接
2. 使用 VLESS 转 Clash 的转换工具 https://acl4ssr-sub.github.io/?hl=zh-CN
3. 转换后导入 Clash 客户端
4. 节点列表里选择之前设置的用户名开头的节点
5. 测试连接是否正常

---

## 六、常用命令

启动管理脚本：

```bash
vasma
```

重启 VPS：

```bash
reboot
```

查看节点配置：

```bash
vasma
```

然后在菜单里选择查看账号 / 节点信息相关选项。

---

## 七、注意事项

1. 端口推荐使用 `443`
2. Reality 伪装域名可以填写：

```text
www.microsoft.com
```

3. 安装完成后一定要保存好 `vless://` 链接
4. 如果连接失败，优先检查：

   * VPS 防火墙是否放行 443 端口
   * 云服务商安全组是否放行 443 端口
   * Clash 配置是否转换正确
   * VPS 是否已经重启完成
5. 修改配置后，建议重启相关服务或直接重启 VPS

---

## 八、简化流程总结

```text
1. SSH 登录 VPS
2. 执行安装脚本
3. 输入 vasma
4. 选择 3：一键无域名 Reality
5. 选择 1：Xray-core
6. 端口填 443
7. 伪装域名填 www.microsoft.com
8. 保存 vless:// 节点链接
9. vasma 里安装 BBR + FQ
10. reboot 重启 VPS
11. 将 vless:// 转 Clash 订阅
12. 导入 Clash 并选择节点使用
```
