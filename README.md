# TVTestAnnictRecorder

[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/SlashNephy/TVTestAnnictRecorder/latest?style=flat-square)](https://github.com/SlashNephy/TVTestAnnictRecorder/actions)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/SlashNephy/TVTestAnnictRecorder?style=flat-square)](https://github.com/SlashNephy/TVTestAnnictRecorder/releases)

📝 視聴したアニメの視聴記録を自動で Annict に送信する TVTest プラグイン

## Flow

- TVTest から現在の番組を取得
- saya の [チャンネル定義](https://github.com/SlashNephy/saya/blob/dev/docs/definitions.yml) からしょぼいカレンダーの ChID を取得
- 番組の放送時間からしょぼいカレンダーに問い合わせて, しょぼいカレンダー TID と話数を取得
- TID から Annict 作品 ID を取得 (`AnnictIds.h`)
- Annict 作品 ID と話数から Annict に問い合わせて, Annict エピソード ID を取得
- Annict エピソード ID に視聴記録をつける

## Configuration

`AnnictRecorder.ini` を編集してください。

```ini
[Annict]
; Annict の個人用アクセストークンを設定します。トークンが設定されていない場合, 記録は行いません。
; https://annict.jp/settings/tokens/new で発行できます。
; スコープを「読み取り + 書き込み」に設定する必要があります。
; Token=xxx

[Record]
; 視聴を開始してから Annict に記録するまでの閾値 (%)
; 例えば 20 の場合, 番組の放送時間の 20% 視聴した場合に記録します。
; 途中から視聴した場合は視聴開始時間から 20% 分視聴した場合に記録します。
; TvtPlay で再生時にも同様な判定が行われます。
; デフォルト値: 20
;ThresholdPercent=20
```

## Build

依存関係は [vcpkg](https://github.com/microsoft/vcpkg) で管理されています。

```bat
vcpkg integrate install

msbuild TVTestAnnictRecorder.sln -property:Configuration="Release" -property:Platform="x64" -m
```

## License

TVTestAnnictRecorder is provided under the MIT license.
