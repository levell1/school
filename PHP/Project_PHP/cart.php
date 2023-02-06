<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">

<link rel="stylesheet" type="text/css" href="./css/cart.css">
</head>
<body>
<header>
    <?php include "header.php";?>
</header>
<section>
   	<div id="cart_box">
      <h3 id="member_title">
        <?=$userid?>님 장바구니
    </h3>
      <ul id="shop_list">
        <li>
          <span class="col1">상품 정보</span>
          <span class="col2">수량</span>
          <span class="col3">총가격</span>
          <span class="col4"></span>
        </li>
<form method="post" name="form">
        <?php
        $con = mysqli_connect("localhost", "user1", "12345", "sample");
        mysqli_set_charset($con,"utf8");
        $sql = "select * from orderlist where userid ='$userid' and gubon='장바구니' order by num";
        $result = mysqli_query($con, $sql);
          $total=0;
        while( $row = mysqli_fetch_array($result) )
        	{
            $num = $row["num"];
            $name = $row["name"];
            $filename = $row["filename"];
            $price = $row["price"];
            $amount = $row["amount"];
            $totalprice = $row["totalprice"];
            $orderuserid = $row["userid"];
            $gubon = $row["gubon"];
            $state = $row["state"];
		?>

                <li>
                  <a href="productcart.php?name=<?=$name?>"class="col1"><img src="<?=$filename?>" alt="debug"> <br><?=$name?></a>
                  <span class="col2"><?=$amount?></span>
                  
                  <span class="col3"><?=$totalprice?></span>
                  <span class="col4"><button  type="submit" onclick="javascript: form.action='cart_delete.php?num=<?=$num?>'">삭제</button>
                  </span>
                </li>

        				<?php

                $total= $totalprice+$total;
              }

          mysqli_close($con);

        ?>
        <div>

          <span class="col5">총금액 : <?=$total?></span>
          <input type="hidden" name="total" value="<?=$total?>">
      </div>
      <button class="col1" onclick="javascript: form.action='order_update.php?userid=<?=$orderuserid?>'">주문하기</button>
  </form>
      </ul>
      <h3 id="member_title">
        <?=$userid?>님 주문현황
    </h3>
      <ul id="shop_list">
        <li>
          <span class="col1">상품 정보</span>
          <span class="col4">수량</span>
          <span class="col3">총가격</span>
          <span class="col3">주문 상황</span>
          <span class="col4"></span>
        </li>
<form method="post" name="form">
        <?php
        $con = mysqli_connect("localhost", "user1", "12345", "sample");
        mysqli_set_charset($con,"utf8");
        $sql = "select * from orderlist where userid ='$userid' and gubon!='장바구니' order by num desc";
        $result = mysqli_query($con, $sql);
          $total=0;
        while( $row = mysqli_fetch_array($result) )
        	{
            $num = $row["num"];
            $name = $row["name"];
            $filename = $row["filename"];
            $price = $row["price"];
            $amount = $row["amount"];
            $totalprice = $row["totalprice"];
            $orderuserid = $row["userid"];
            $gubon = $row["gubon"];
            $state = $row["state"];
		?>

                <li>
                  <a href="productcart.php?name=<?=$name?>"class="col1"><img src="<?=$filename?>" alt="debug"> <br><?=$name?></a>
                  <span class="col4"><?=$amount?></span>
                  <span class="col3"><?=$totalprice?></span>
                  <span class="col3"><?=$state?></span>
                  <span class="col4"><button  type="submit" onclick="javascript: form.action='cart_delete.php?num=<?=$num?>'">취소,배달완료</button>
                  </span>
                </li>

        				<?php


              }

          mysqli_close($con);

        ?>

    </form>
      </ul>
      </div>
</section>
<footer>
    <?php include "footer.php";?>
</footer>
</body>
</html>
