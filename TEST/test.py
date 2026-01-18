import sys
import platform
import importlib

def print_header(title):
    print(f"\n{'='*10} {title} {'='*10}")

def check_library(lib_name, import_name=None):
    if import_name is None:
        import_name = lib_name
    
    try:
        module = importlib.import_module(import_name)
        version = getattr(module, '__version__', 'Installed (No version attr)')
        print(f"✅ {lib_name:<20} : {version}")
        return True, module
    except ImportError:
        print(f"❌ {lib_name:<20} : Not Found")
        return False, None

# --- 1. Python環境の基本情報 ---
print_header("Python Environment")
print(f"Implementation       : {platform.python_implementation()}")
print(f"Python Version       : {platform.python_version()}")
print(f"Compiler             : {platform.python_compiler()}")
print(f"Executable           : {sys.executable}")

if platform.python_implementation() == "PyPy":
    print("\n✨ Success! You are running on PyPy (Fast!)")
else:
    print("\n⚠️  Warning: You are running on CPython (Standard). For AtCoder, PyPy is recommended.")

# --- 2. ライブラリのインストール確認 ---
print_header("Library Versions")

# AtCoderでよく使うライブラリリスト (パッケージ名, インポート名)
libraries = [
    ("numpy", "numpy"),
    ("networkx", "networkx"),
    ("sortedcontainers", "sortedcontainers"),
    ("more-itertools", "more_itertools"),
    ("ac-library-python", "atcoder"),  # ACL
    ("bitarray", "bitarray"),
    ("scipy", "scipy"),          # 重いため除外した場合はNot Foundになります
    ("scikit-learn", "sklearn")  # 同上
]

modules = {}
for lib_name, import_name in libraries:
    _, mod = check_library(lib_name, import_name)
    if mod:
        modules[import_name] = mod

# --- 3. 動作テスト (NumPy) ---
print_header("Simple Calculation Test")

if "numpy" in modules:
    try:
        np = modules["numpy"]
        a = np.array([1, 2, 3])
        b = np.array([4, 5, 6])
        result = np.dot(a, b)
        print(f"NumPy Dot Product Test : {a} dot {b} = {result}")
        if result == 32:
            print("✅ NumPy is working correctly!")
        else:
            print("❌ NumPy calculation error.")
    except Exception as e:
        print(f"❌ NumPy crashed: {e}")
else:
    print("Skipping NumPy test (not installed)")

print("\n" + "="*35 + "\n")