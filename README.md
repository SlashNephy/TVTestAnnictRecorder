# TVTestAnnictRecorder

📝 [WIP] 視聴したアニメの視聴記録を自動で Annict に送信する TVTest プラグイン

- TVTest から現在の番組を取得
- 前作った saya の [チャンネル定義ファイル](https://github.com/SlashNephy/saya/blob/dev/docs/definitions.yml) からしょぼいカレンダーの ChID を取得
- 番組の放送時間をしょぼいカレンダーに問い合わせ
- しょぼいカレンダー ID (TID) から Annict に問い合わせ (← ｲﾏｺｺ)
- Annict に視聴記録をつける

## Build (Dependencies)

```bat
git clone --recursive https://github.com/SlashNephy/TVTestAnnictRecorder

cd .\TVTestAnnictRecorder\Thirdparty\yaml-cpp
mkdir build
cd .\build
cmake ..
msbuild YAML_CPP.sln -property:Platform="x64" -m

cd .\TVTestAnnictRecorder\Thirdparty\json
mkdir build
cd .\build
cmake ..
msbuild nlohmann_json.sln -property:Platform="x64" -m

cd C:\
git clone https://github.com/Microsoft/vcpkg.git

cd .\vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
.\vcpkg install cpr
```

## Build (Plugin)

依存関係のライブラリはビルド済です。上記のビルドを行うことなくプラグインをビルドできます。  
現在 x64 ビルドのみサポートしています。

```bat
git clone https://github.com/SlashNephy/TVTestAnnictRecorder

cd .\TVTestAnnictRecorder
msbuild TVTestAnnictRecorder.sln -property:Configuration="Release" -property:Platform="x64" -m
```
