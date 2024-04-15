QtCreator で設計された音楽プレーヤー、UI デザインは sonymusic ロゴにインスパイアされており、優れたコンセプトで Spotify や Apple Music、さらには Tencent Music と競合できるものです。

A music player designed by QtCreator, UI design inspired by sonymusic logo, good concept and compete with Spotify or Apple Music even Tencent Music.

# アプリを開発した動機
世の中で、いろんなMUSICアプリがあります。欧米はApple music、Spotifyとか流行しています。中国の場合Tencent Musicが今はもう市場の大半支配された。

一方、今の日本はもう80年代のゴルデン時代じゃ無いけど、日本は東アジアおよび世界で文化を輸出しつづける大国であり、ハイエンド市場を堅持しつづけています。アニメ、ゲム、アイドルなどのサブカルチャーは、この競争において他国が对抗できないほど强力です。しかし、一方で、日本国内では支配的なおんがくソフトウェアが誕生していないことが残念であり、特にトップ企業であるソニーはその責任を逃れることは難しいと考えています。それゆえ、私は次のようなソフトウェアをかいはつしました。

# Tool, Library and Environment
Complier is MSVC(Visual Studio 2019), and use QT 5.15 for UI design.

The protocol is H264("AVC" Advanced Video Coding), and I use the FFmpeg as stream media library.
## FFmpeg
> Notion: I won't introduce how to build the development environment for VS2019 and QT 5.15, you need to learn it by yourself.

*FFmpeg is the leading multimedia framework, able to decode, encode, transcode, mux, demux, stream, filter and play pretty much anything that humans and machines have created. It supports the most obscure ancient formats up to the cutting edge. No matter if they were designed by some standards committee, the community or a corporation. It is also highly portable: FFmpeg compiles, runs, and passes our testing infrastructure FATE across Linux, Mac OS X, Microsoft Windows, the BSDs, Solaris, etc. under a wide variety of build environments, machine architectures, and configurations.*

**Download:** [https://ffmpeg.org](https://ffmpeg.org)


> 中国の方はこちらへ

**Source Code：** [http://ffmpeg.club](http://ffmpeg.club)

**GitHub：** [https://github.com/FFmpeg/FFmpeg](https://github.com/FFmpeg/FFmpeg)

*Then use this command for complie.*

``` bash
git clone https://git.ffmpeg.org/ffmpeg.git ffmpeg
cd ffmpeg
mkdir build
make && install
```

*You may need Cmake and other Tools!*
# 実物ご覧でください
![image](https://github.com/KokoroSinx/SonyMusicPlayer/blob/main/d8af38cb0bd9295c3e7fb7f31f313be1.png?raw=true)

# 機能
## 音楽の再生
音楽プレーヤーとして、最も重要な機能は音楽を再生することです。H264プロトコルを選択したため、高品質の音源を再生する要求にも応えることができます。また、サーバーから音楽をローカルにダウンロードする機能や、進行状況バーを使用した再生位置の調整を設計しました。曲送りや曲戻しの機能もあり、自分だけのプレイリストを作成することも可能です。さらに、音量調整機能も設計しました。

作为音乐播放器，最重要的功能就是播放音乐。由于编码解码形式选择了H264协议，如果有高品质声源的需求也能够满足。同时设计了从服务器下载音乐到本地的功能，还支持通过进度条的跳转播放。也可以上一首，下一首的切歌，还可以创建属于自己的歌单。此外也设计了一个音量调节的功能。

## lyrics
主要の枠組みを完成した後、私はNosicクラスに歌詞を表示する機能を追加しました。この機能を実現するには同期を取る方法についてある程度の研究が必要ですが、単独の音声だけでは特に難しくありません。しかし、音声や動画、字幕の同期が必要な場合はより多くの学習が必要です。私はまだ学生ですので。

在完成主体框架之后，我在nosic类里添加了显示歌词的功能，实现这一功能需要对如何做到同步有一定的研究。但只是单方面的音频不至于特别麻烦。如果涉及到音频视频和字幕的同步则需要更多的学习，毕竟我还只是个学生。

## mv
将来、アルバムMVの再生機能を追加したいと考えています。つまり、ビデオに関する知識も必要になります。現在、FFmpegを使用してビデオプレーヤーを作成し、そこからビデオ再生機能を指すAPIインターフェースを提供しようと試みています。

我在将来想添加专辑mv播放的功能，也就是说还需要视频方面的知识。目前我在尝试使用FFmpeg制作一个视频播放器，然后在这里提供一个API接口指向打开视频播放功能。

## In the future　将来のこと
制作中にFFmpegチームが作成したサーバーライブラリがあり、ストリーミングメディアのライブ配信サービスに使えることに気付きました。これは将来私も試してみたい方向性と合っています。ただし、企業レベルのインターネットサーバー構築の経験が不足しているため、現時点ではこの計画を保留しています。

同時に、私の最初の目標は、各種のリソースを統合し、このアプリをファン向けのイベントに参加させ、ライブコンサートのチケット抽選も行えるようにすることです。

我在制作的过程中发现FFmpeg团队制作了一个server的库用于流媒体直播推流服务，正好我将来也想尝试一下这个方向。但由于我缺乏企业级的互联网服务器搭建经验，所以暂时搁置。

同时，我的初心是整合各方面的资源，让这个app也能够用于参加主办方为粉丝推出的各种活动，还能进行live演唱会门票的抽选。
