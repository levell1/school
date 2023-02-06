<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/order_list.css">
<link rel="stylesheet" type="text/css" href="./css/board.css">
</head>
<body>
<header>
    <?php include "header.php";?>
</header>
<section>
   	<div id="cart_box">
      <h3 id="member_title">
        주문 관리
    </h3>
      <ul id="shop_list">
        <li>
          <span class="col1">상품 정보</span>
          <span class="col2">수량</span>
          <span class="col2">아이디</span>
          <span class="col3">총가격</span>
          <span class="col3">구분</span>
          <span class="col4"></span>
        </li>
<form method="post" name="form">
        <?php
        if (isset($_GET["page"]))
          $page = $_GET["page"];
        else
          $page = 1;

        $con = mysqli_connect("localhost", "user1", "12345", "sample");
        mysqli_set_charset($con,"utf8");
        $sql = "select * from orderlist where gubon='주문' order by num desc";
        $result = mysqli_query($con, $sql);
        $total_record = mysqli_num_rows($result);

        $scale = 5;

        if ($total_record % $scale == 0)
          $total_page = floor($total_record/$scale);
        else
          $total_page = floor($total_record/$scale) + 1;

        $start = ($page - 1) * $scale;

        $number = $total_record - $start;

       for ($i=$start; $i<$start+$scale && $i < $total_record; $i++)
        {
           mysqli_data_seek($result, $i);
           $row = mysqli_fetch_array($result);
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
                  <span class="col2"><?=$orderuserid?></span>
                  <span class="col3"><?=$totalprice?></span>
                  <span class="col3"><?=$state?></span>
                  <span class="col4"><button onclick="javascript: form.action='order_update_admin.php?state=주문확정&num=<?=$num?>'">주문확정</button></span>
                  <span class="col4"><button onclick="javascript: form.action='order_update_admin.php?state=취소&num=<?=$num?>'">취소하기</button></span>

                </li>

        				<?php

                $number--;
              }

          mysqli_close($con);

        ?>

</form>
      </ul>
      <ul id="page_num">
<?php
	if ($total_page>=2 && $page >= 2)
	{
		$new_page = $page-1;
		echo "<li><a href='admin_order.php?page=$new_page'>◀ 이전</a> </li>";
	}
	else
		echo "<li>&nbsp;</li>";


   	for ($i=1; $i<=$total_page; $i++)
   	{
		if ($page == $i)
		{
			echo "<li><b> $i </b></li>";
		}
		else
		{
			echo "<li><a href='admin_order.php?page=$i'> $i </a><li>";
		}

   	}

   	if ($total_page>=2 && $page != $total_page)
   	{
		$new_page = $page+1;
		echo "<li> <a href='admin_order.php?page=$new_page'>다음 ▶</a> </li>";
	}
	else
		echo "<li>&nbsp;</li>";
?>
			</ul>
      </div>
</section>
<footer>
    <?php include "footer.php";?>
</footer>
</body>
</html>
