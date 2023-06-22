### 概要
・ロボット制作用リポジトリ

  
### 使用方法  

[簡単ver]  
1. code -> zipデータをダウンロード  
2. 各自Arduinoのインストール環境に合わせた場所で解凍  
    ＊デフォルトではC:\Users\[ユーザ名]\OneDrive\ドキュメント\Arduino\
    
    3.Arduinoで開く  

[gitを使う]  

    1. gitの導入
        参考：https://qiita.com/Kenta-Okuda/items/c3dcd60a80a82147e1bf
        手順3-4まで行う->git clone https://github.com/sayaIvy/robot.git

    2. ソースコードを見る
        コマンドプロンプトもしくはPower shellで以下コマンド
        code .
    
    3. ソースコードを編集  
        3-1. ブランチを切る
            作業環境を分けるイメージ
            git switch -c ブランチ名
            ブランチが切り替わっているか確認
            git branch 
            ここで、自分が設定したブランチ名が緑色で表示されたらOk
        3-2. ソースコードを編集

    4. ソースコードをアップロード
        git add .  
        git commit -m "メッセージ"
            * メッセージは、どんな変更をしたかを書く  
        git push origin ブランチ名  

    5. Web上で確認
        https://github.com/sayaIvy/robot.git
