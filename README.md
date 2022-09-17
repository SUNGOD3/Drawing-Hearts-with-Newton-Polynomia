# Drawing-Hearts-with-Newton-Polynomia

## Problem Description

1.
    產生能夠拚成心型的12個點𝑃𝑖(𝑋𝑖, 𝑌𝑖)，𝑋𝑖與𝑌𝑖分別為以t作為參數的函數，𝑋𝑖=𝑋(𝑡𝑖)、𝑌𝑖=𝑌(𝑡𝑖)，而t的產生方式有兩種: <br><br>
    A.Chord-length : 𝑡𝑖=∑𝑙𝑗 , i=0~12，𝑙𝑗表示第j點與第j+1點之間的距離，𝑡𝑖代表到第i個點的累計距離 <br>
    B.Uniform : 𝑡𝑖=𝑖


2.
    <br>A.將上述點代入Newton Polynomial 做計算，並顯示係數(coefficient)。<br>
    B.透過計算出來的Newton Polynomial產生40 個點，將這40 個點連線並繪圖出來。

3.
    <br>A.何種參數方法繪圖出來的結果較佳?原因為何? <br>
    B.嘗試產生另一種資料集，點的位置與先前不同，看看繪圖出來的結果是否不同?
    
4.
    採用分段逼近的方式，建立四個Newton Polynomial去產生樣本點。<br>
    1.右半心型的部分可直接由左半邊的樣本點Reflection產生 <br>
    2.樣本點數目可自由定義 <br><br>
    A.將產生的樣本點相連並繪圖出來，與之前的結果相比較。<br>
    B.檢查𝑆𝑖(𝑡)在𝑃2、𝑃3、𝑃4的一次微分值(𝐶1−𝑐𝑜𝑛𝑡𝑖𝑛𝑢𝑖𝑡𝑦)是否相同。
