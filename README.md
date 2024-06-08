# For the King

## 內部規範

### Coding Style

- 不可使用具有外部連結的 Global Variable；若要使用 Global Variable，則需要確保其他人只能依靠額外的 Function 來存取 Global Variable 的 Data
- Class 中的 Data 不可被外部操作直接存取，需要建立專門的 Getter 與 Setter
- Function 行數不宜超過 150 行
- Function 傳入的 Variable 不能超過 7 個，並且 Function 內部不能使用**非 Const**的 Global Variable
- Function 的縮進次數不應超過 4，否則需要額外使用條件反轉或 Helper
- 每個 Source File 只能引用其相同名稱的 Header File
- 若函式具有 inline，則應該放在檔案後綴為 .inl 的同名檔案中，作為介面的實現
- 每個 Header File 都需要有註解
- 命名風格統一為駝峰式命名法

### Commit Style

Commit 必須按照以下的格式進行

```
{HEADER} - 摘要本次 Commit 的內容
(OPTION) <Body> - 詳細說明這次的內容
(OPTION) <Footer> - 額外註記
```

Header 作為摘記不要過長；Body 可以描述這次提交的詳細內容；Footer 可以做為額外註記使用

- Headers
    - FEAT : 新的功能
    - FIX : 修復錯誤
    - DOCS : Document 相關的修改 (CHANGELOG、README、...)
    - PERF : 效能改善，或是增加追蹤效能的 Code
    - TEST : 新增測試文件
    - STYLE : 單純修改程式碼中的美觀排版
    - DEPRECATE : 淘汰某些不必要的 Feature 或是功能
    - REFACTOR : 不添加新功能或是修復 Bug 的情況下重構程式架構 (拆成更小的模組、更好的寫法、...)
    - RELEASE : 和版本相關的註記
    - CI : 對於 CI 相關設定的調整

Ref : https://isoneet.org/web-learning/devTools/git.html#commit-message

### Development Criterion

在開發新功能時必須新增 Branch，並且需先和 Main Branch 嘗試 Merge，並且在 Merge 後沒有出現 Bug 時才能發送 Pull Request 和 Main Branch 做 Merge

Branch 必須按照以下命名規範

```
{NAME}-{STATUS}
```

- Name
    - Name 可以放正在進行開發的 class 或是 Feature 的名稱
- Status
    - DEV : 開發新功能
    - FIX : 修復程式 Bug
    - REBUILD : 重構程式架構

如果不會使用 Branch 以下有提供命令

```
// 建立 Branch
git checkout -b className-DEV

// 切換 Branch
git checkout branchName

// 確認目前所在 Branch

git status
git checkout
```

## Members

- B11215013 徐牧遠
- B11230040 劉祐呈
- B11215024 劉柏毅
- B11230017 吳秉彥
- B11230015 蕭天浩

## Quick Start

## Contribution

### B11215013 徐牧遠

### B11230040 劉祐呈

### B11215024 劉柏毅

### B11230017 吳秉彥

### B11230015 蕭天浩
