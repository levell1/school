<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/main.css">
<link rel="stylesheet" type="text/css" href="./css/shop.css">

<style>
</style>
</head>
<body>
	<header>
    	<?php include "header.php";?>
  </header>

<div id="intro_head">
	<p>스토어</p>
</div>

<div id="shop_top">
	<ul id="top_menu">
		<li><a id="listLogo" href="shop.php">전체</a> </li>
		<li><a id="listLogo" href="shop2.php?kind=문구">문구</a> </li>
		<li><a id="listLogo" href="shop2.php?kind=퀼트제품">퀼트제품</a></li>
		<li><a id="listLogo" href="shop2.php?kind=기타">기타</a></li>
	</ul>
</div>

<div id="now">
<?php
$kind  = $_GET["kind"];
$con = mysqli_connect("localhost", "user1", "12345", "sample");
mysqli_set_charset($con,"utf8");
$sql = "select * from store WHERE kind = '$kind'";
	$result = mysqli_query($con, $sql);
	while( $row = mysqli_fetch_array($result) )
	{
		$num         = $row["num"];
		$kind        = $row["kind"];
		$name        = $row["name"];
		$filename    = $row["filename"];
		$price  = $row["price"];

				$file_path = "data/".$filename;
				?>
				<a id="list" href="product.php?num=<?=$num?>">
					<div class="thumbDiv">
						<div id="list_img">
							<img src="<?=$file_path?>" alt="debug">
						</div>
					</div>
					<div>
						<div>이름 : <?=$name?></div>
						<div>
							<span>가격 : <?=$price?></span>
						</div>
					</div>
				</a>
				<?php
	}
?>

</div>

	<footer>
    	<?php include "footer.php";?>
  </footer>

</body>
</html>
