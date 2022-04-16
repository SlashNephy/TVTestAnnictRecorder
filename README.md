# TVTestAnnictRecorder

[![GitHub Workflow Status](https://img.shields.io/github/workflow/status/SlashNephy/TVTestAnnictRecorder/latest?style=flat-square)](https://github.com/SlashNephy/TVTestAnnictRecorder/actions)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/SlashNephy/TVTestAnnictRecorder?style=flat-square)](https://github.com/SlashNephy/TVTestAnnictRecorder/releases)

📝 視聴したアニメを自動で [Annict](https://annict.com/) に記録する TVTest プラグイン (TVTest 0.9.0 以降が必要)

[![statusbar.png](https://i.imgur.com/vZDneZO.png)](https://github.com/SlashNephy/TVTestAnnictRecorder)

## Features

- Annict へ視聴したアニメの該当エピソードの記録を自動で行います。
  - [TvtPlay](https://github.com/xtne6f/TvtPlay) でファイル再生時にも動作します。
  - 指定した時間だけ視聴したときに記録を行います。(デフォルト値は放送時間の 20%)
  - [しょぼいカレンダー](https://cal.syoboi.jp/) に登録されている番組で機能します。(ほとんど網羅されています。)
  - しょぼいカレンダーにデータのない AT-X のリピート放送や, 一挙放送にも対応しています。
  - 番組に複数のエピソードがある場合 (2話同時放送等) すべてのエピソードに記録を行います。
  - ステータスバーに Annict への記録状況が通知され, クリックした際には該当の Annict のページに飛ぶようになっています。
- 次のオプションがあります。
  - 記録と同時に Twitter や Facebook に投稿する。
  - 第1話 (または最終話以外のエピソード) を視聴した際に Annict での作品のステータスを「見てる」に変更する。
  - 最終話を視聴した際に Annict での作品のステータスを「見た」に変更する。
  - 既に「見た」になっている作品では「見てる」に変更しない。

## Limitations

TVTestAnnictRecorder が記録を行うためには以下の条件を満たす必要があります。

- [しょぼいカレンダー](https://cal.syoboi.jp) に放送局が登録されている
  - 一覧はしょぼいカレンダーの [登録チャンネル](https://cal.syoboi.jp/mng?Action=ShowChList) から確認できます。
  - 一覧にない場合 (放送局が在京キー局の系列局の場合) も問題ありません。
- しょぼいカレンダーに放送時間が登録されている
  - 有志の方々がデータを登録されています。ありがとうございます。
  - AT-X の場合, リピート放送はしょぼいカレンダーに放送時間が登録されていません。その場合は番組名から作品名と話数を抽出します。Annict に完全一致する作品名が見つかった場合にのみ記録が行われます。
- しょぼいカレンダーと Annict で相互変換できる
  - [kawaiioverflow/arm](https://github.com/kawaiioverflow/arm) を利用しています。
  - 頻繁に更新されており, 最近のアニメなら間違いなく追加されています。ありがとうございます。

## Configuration

`AnnictRecorder.ini` を編集してください。

```ini
[Annict]
; Annict の個人用アクセストークンを設定します。トークンが設定されていない場合, 記録は行いません。
; https://annict.com/settings/tokens/new で発行できます。
; スコープを「読み取り + 書き込み」に設定する必要があります。
; Token=xxx

[Record]
; 視聴を開始してから Annict に記録するまでの閾値 (%)
; 例えば 20 の場合, 番組の放送時間の 20% 視聴した場合に記録します。
; 途中から視聴した場合は視聴開始時間から 20% 分視聴した場合に記録します。
; TvtPlay で再生時にも同様な判定が行われます。
; デフォルト値: 20
; ThresholdPercent=20

; エピソードの記録と同時に Twitter に投稿するかどうか。
; Annict に登録されている Twitter アカウントが使用されます。
; デフォルト値: 0
; ShareOnTwitter=1

; エピソードの記録と同時に Facebook に投稿するかどうか。
; Annict に登録されている Facebook アカウントが使用されます。
; デフォルト値: 0
; ShareOnFacebook=1

; 第1話を視聴した際に作品のステータスを「見てる」に変更するかどうか。
; デフォルト値: 0
; SetWatchingStatusInFirstEpisode=1

; 第1話に限らず視聴した作品のステータスを「見てる」に変更するかどうか。(最終話を除く)
; デフォルト値: 0
; SetWatchingStatusInAnyEpisodes=1

; 最終話を視聴した際に作品のステータスを「見た」に変更するかどうか。
; デフォルト値: 0
; SetWatchedInLastEpisode=1

; 既に「見た」になっている作品では上記のオプションにより「見てる」に変更されないようにするかどうか。
; デフォルト値: 0
; SkipUpdateStatusIfAlreadyWatched=1

; 既に「視聴中止」になっている作品では上記のオプションにより「見てる」に変更されないようにするかどうか。
; デフォルト値: 0
; SkipUpdateStatusIfAlreadyStopWatching=1

; 既に「見た」となっている作品でも [新] フラグが付いている番組を視聴した際に上記のオプションにより「見てる」に変更されるようにするかどうか。
; 分割2クールのように同じ作品であっても [終] のあとに [新] となるようなケースで有効です。
; デフォルト値: 0
; SetWatchingStatusOnFirstEpisodeEvenIfWatched=1

; 1 に変更すると実際に記録は行いません。デバッグ用です。
; デフォルト値: 0
; DryRun=1
```

## Build

依存関係は [vcpkg](https://github.com/microsoft/vcpkg) で管理されています。

```bat
vcpkg integrate install

msbuild TVTestAnnictRecorder.sln -property:Configuration="Release" -property:Platform="x64" -m
```

## Acknowledgements

TVTestAnnictRecorder は以下のサービス, OSS プロジェクトを利用しています。ありがとうございます。

- [しょぼいカレンダー](https://cal.syoboi.jp)
- [Annict](https://annict.com)
- [kawaiioverflow/arm](https://github.com/kawaiioverflow/arm)
- [xtne6f/TvtPlay](https://github.com/xtne6f/TvtPlay)
- [whoshuu/cpr](https://github.com/whoshuu/cpr)
- [jbeder/yaml-cpp](https://github.com/jbeder/yaml-cpp)
- [nlohmann/json](https://github.com/nlohmann/json)
- [zeux/pugixml](https://github.com/zeux/pugixml)
- [microsoft/vcpkg](https://github.com/microsoft/vcpkg)

## License

TVTestAnnictRecorder is provided under the MIT license.
