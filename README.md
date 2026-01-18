# AtCoder Python Environment (uv + PyPy 3.10)

AtCoderのPyPy3提出環境（Python 3.10 + PyPy）を再現したローカル実行環境です。
高速なパッケージマネージャー `uv` を使用して管理しており、コマンド一発で環境構築が可能です。

## 🛠 環境構築 (Setup)

このリポジトリを GitHub からクローンして、手元で実行環境を再現する手順です。
**Python や PyPy を事前にインストールする必要はありません。** `uv` がすべて自動で行います。

### 1. `uv` のインストール
まだ `uv` を入れていない場合は、以下のコマンドでインストールしてください。

**Mac / Linux (WSL含む):**
```bash
curl -LsSf [https://astral.sh/uv/install.sh](https://astral.sh/uv/install.sh) | sh
```

**Windows (PowerShell):**
```powershell
powershell -c "irm [https://astral.sh/uv/install.ps1](https://astral.sh/uv/install.ps1) | iex"
```

### 2. リポジトリのクローン
```bash
git clone [https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git)
cd YOUR_REPO_NAME
```

### 3. 環境の同期 (Sync)
以下のコマンドを実行すると、自動的に **PyPy 3.10** がダウンロードされ、仮想環境 (`.venv`) が作成され、必要なライブラリがインストールされます。

```bash
uv sync
```

### 4. 動作確認
以下のコマンドを実行して、PyPy 3.10 と表示されれば完了です。

```bash
uv run python --version
# 出力例: Python 3.10.16 ... [PyPy 7.3.19 ...]
```

---

## 🚀 使い方 (Usage)

仮想環境を手動で activate する必要はありません。`uv run` コマンドを使用します。

### コードの実行
```bash
# main.py を実行する
uv run main.py

# ワンライナーなどで実行する場合
uv run python -c "print(10**9 + 7)"
```

### 便利なコマンド
```bash
# インストール済みライブラリの一覧確認
uv pip list

# 仮想環境内でシェルを起動（exitで抜ける）
uv run bash
```

### 推奨エイリアス
毎回 `uv run` を打つのが手間な場合、`.bashrc` や `.zshrc` に以下を設定すると便利です。
```bash
alias pypy="uv run python"
# 使用例: pypy main.py
```

---

## 📦 環境詳細 (Environment)

* **Runtime**: PyPy 3.10 (Pinned via `uv python pin pypy@3.10`)
* **Manager**: uv

### インストール済み主要ライブラリ
AtCoderの言語環境に合わせてバージョン指定しています（一部ビルド困難なものを除く）。

| Library | Version | Note |
| :--- | :--- | :--- |
| `numpy` | 1.24.1 | 数値計算 |
| `networkx` | 3.0 | グラフ理論 |
| `ac-library-python` | Latest | AtCoder Library (ACL) |
| `sortedcontainers` | 2.4.0 | 平衡二分探索木など |
| `more-itertools` | 9.0.0 | イテレータ拡張 |
| `sympy` | 1.11.1 | 数式処理 |
| `z3-solver` | 4.12.1.0 | 制約ソルバ |
| `bitarray` | 2.6.2 | ビット操作 |
| `pulp` | 2.7.0 | 線形計画法 |
| `mpmath` | 1.2.1 | 任意精度演算 |

> **Note:**
> ローカル環境でのビルド負荷（Fortranコンパイラ不足等）を回避するため、`scipy`, `scikit-learn`, `pandas`, `shapely` は意図的に除外しています。これらはABC（Beginner Contest）レベルでは通常不要です。

---

## ⚠️ トラブルシューティング

**Q. Pythonのバージョンが勝手に変わる / CPythonになってしまう**
A. プロジェクト設定でバージョンを固定し直してください。
```bash
uv python pin pypy@3.10
uv sync
```

**Q. 実行時に `ModuleNotFoundError` が出る**
A. 必ず `uv run` を付けて実行してください。単に `python main.py` と打つと、システム（PC本体）のPythonが使われてしまいます。

**Q. 仮想環境をリセットしたい**
A. `.venv` フォルダを削除して作り直してください。
```bash
rm -rf .venv
uv sync
```