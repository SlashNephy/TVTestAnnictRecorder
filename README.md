# TVTestAnnictRecorder

[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/SlashNephy/TVTestAnnictRecorder/latest?style=flat-square)](https://github.com/SlashNephy/TVTestAnnictRecorder/actions)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/SlashNephy/TVTestAnnictRecorder?style=flat-square)](https://github.com/SlashNephy/TVTestAnnictRecorder/releases)

📝 [WIP] 視聴したアニメの視聴記録を自動で Annict に送信する TVTest プラグイン

- TVTest から現在の番組を取得
- 前作った saya の [チャンネル定義ファイル](https://github.com/SlashNephy/saya/blob/dev/docs/definitions.yml) からしょぼいカレンダーの ChID を取得
- 番組の放送時間をしょぼいカレンダーに問い合わせ
- しょぼいカレンダー ID (TID) から Annict に問い合わせ (← ｲﾏｺｺ)
- Annict に視聴記録をつける

## Build

依存関係は [vcpkg](https://github.com/microsoft/vcpkg) で管理されています。

```bat
vcpkg integrate install

msbuild TVTestAnnictRecorder.sln -property:Configuration="Release" -property:Platform="x64" -m
```

## License

TVTestAnnictRecorder is provided under the MIT license.
