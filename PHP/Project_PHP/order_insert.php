<?php

session_start();
if (isset($_SESSION["userid"])) $userlevel = $_SESSION["userlevel"];
else $userlevel = "";

if (!isset($_SESSION["userid"]))
{
  echo("
      <script>
      alert('로그인후 사용해주세요');
      history.go(-1)
      </script>
  ");
}else {

if (isset($_SESSION["userpoint"])) $userpoint = $_SESSION["userpoint"];
else $userpoint = "";

$name = $_POST["name"];
$filename = $_POST["file_path"];
$price = $_POST["price"];
$amount = $_POST["amount"];
$totalprice = $price*$amount;
$userid = $_POST["userid"];
$gubon = $_GET["gubon"];

$con = mysqli_connect("localhost", "user1", "12345", "sample");
mysqli_set_charset($con,"utf8");
$sql = "select point from members where id='$userid'";
$result = mysqli_query($con, $sql);
$row = mysqli_fetch_array($result);
$point=  $row["point"];
if ($point<$totalprice)
{
  echo("
      <script>
      alert('포인트가 부족합니다.');
      location.href = 'cart.php';
      </script>
  ");
}else {
$new_point = $row["point"] - $totalprice;
$sql = "update members set point=$new_point where id='$userid'";
mysqli_query($con, $sql);

	  $sql = "insert into orderlist(name, filename, price, amount, totalprice, userid, gubon,state) ";
	  $sql .= "values('$name', '$filename', $price, $amount, $totalprice, '$userid', '$gubon','대기')";
	  mysqli_query($con, $sql); 



    mysqli_close($con);
    echo "
	      <script>
            alert('포인트로 주문하였습니다.');
            location.href = 'cart.php';
	      </script>
	  ";
}
}
?>
