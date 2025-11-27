## 🟦 一、Git 基础概念（最精简版）

|概念|说明|
|---|---|
|工作区（Working Directory）|你平时打开的文件夹|
|暂存区（Stage / Index）|`git add` 后的地方|
|本地仓库（Local Repo）|`git commit` 存在本地|
|远程仓库（Remote Repo）|GitHub / Gitee 等|

---

## 🟦 二、常用 Git 命令（按流程分类）

### 📌 1. 初始化仓库

`git init`

---

### 📌 2. 查看状态

`git status`

---

### 📌 3. 添加到暂存区

`git add . git add 文件名`

---

### 📌 4. 提交

`git commit -m "提交信息"`

---

### 📌 5. 远程仓库相关

`git remote add origin <url>     # 设置远程仓库 git remote remove origin        # 删除远程仓库 git remote -v                   # 查看远程仓库`

---

### 📌 6. 重命名分支（常用于 master → main）

`git branch -M main`

---

### 📌 7. 推送到远程

首次推送（设置 upstream）：

`git push -u origin main`

之后：

`git push`

---

### 📌 8. 拉取远程更改

`git pull`

---

## 🟦 三、常见场景解决方案

### 📌 A. 改写最新提交信息

`git commit --amend -m "新的信息"`

---

### 📌 B. 撤回已添加（不丢文件）

`git reset HEAD 文件名`

---

### 📌 C. 撤回最近一次提交（保留文件）

`git reset --soft HEAD~1`

---

### 📌 D. 撤回最近一次提交（不保留暂存区）

`git reset --mixed HEAD~1`

---

### 📌 E. 回退到某次提交

`git reset --hard <commit-id>`

⚠谨慎：会丢掉之后所有提交。

---

### 📌 F. 创建分支 / 切换分支

`git branch 新分支 git checkout 新分支`

一条命令创建并切换：

`git checkout -b 新分支`

---

### 📌 G. 合并分支

`git merge 分支名`