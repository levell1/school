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
}else{
    $name = $_POST["name"];
    $filename = $_POST["file_path"];
    $price = $_POST["price"];
    $amount = $_POST["amount"];
    $totalprice = $price*$amount;
    $userid = $_POST["userid"];
    $gubon = $_GET["gubon"];


    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    mysqli_set_charset($con,"utf8");
	  $sql = "insert into orderlist(name, filename, price, amount, totalprice, userid, gubon,state) ";
	  $sql .= "values('$name', '$filename', $price, $amount, $totalprice, '$userid', '$gubon','대기')";
	  mysqli_query($con, $sql); 
    mysqli_close($con);

    echo "
	      <script>
            alert('추가되었습니다.');
	          location.href = 'cart.php';
	      </script>
	  ";
  }
?>
