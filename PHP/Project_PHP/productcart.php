<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/main.css">
<link rel="stylesheet" type="text/css" href="./css/shop.css">
<link rel="stylesheet" type="text/css" href="./css/product.css">
<style>
</style>
</head>
<script language="JavaScript">
var a = 1;
function add(){
		var textBox = document.getElementById("amount");
	a++;

	textBox.value = a;

}
function del(){
	var textBox = document.getElementById("amount");
	if (textBox.value<2) {
		return;
	}
	a--;


	textBox.value = a;

}

</script>
<body>
	<header>
    	<?php include "header.php";?>
  </header>
<br><br><br><br>

<?php
$name  = $_GET["name"];
$con = mysqli_connect("localhost", "user1", "12345", "sample");
mysqli_set_charset($con,"utf8");
  $sql = "select * from store where name = '$name' ";
	$result = mysqli_query($con, $sql);
	$row = mysqli_fetch_array($result);
		$num         = $row["num"];
		$kind        = $row["kind"];
		$name        = $row["name"];
		$filename    = $row["filename"];
		$price  = $row["price"];

				$file_path = "data/".$filename;
				?>
				<form name="form" method="post">

					<input type="hidden" name="userid" value="<?=$userid?>">

        <div id="now1">
						<div id="list_img1">
							<input type="hidden" name="file_path" value="<?=$file_path?>">
							<img src="<?=$file_path?>" alt="debug">
						</div>
					<div class="info">
            <div id="product_head">
							<input type="hidden" name="name" value="<?=$name?>">
						     <h4><?=$name?></h4>
						</div>
            <div id="product_price">
							<input type="hidden" name="price" value="<?=$price?>">
							  <span><?=$price?>원</span>
						</div>
            <div id="product_num">

                수량 :
								<input type="button" value=" + " onclick="add();">
                <input type="text" id="amount" name="amount"  value="1" size="3">
                <input type="button" value=" - " onclick="del();"></div><br>
<Br><br>
								<button id="buttonst" type="submit" value="upd" onclick="javascript: form.action='order_insert.php?gubon=주문 ' ">구매 하기</button>
								<button id="buttonst1" type="submit" value="del" onclick="javascript: form.action='order_insertbag.php?gubon=장바구니 ' ">장바구니</button>

                </form>


					</div>
        </div>
				<?php

?>



	<footer>
    	<?php include "footer.php";?>
  </footer>

</body>
</html>
