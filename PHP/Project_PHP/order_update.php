<?php
    session_start();

    $orderuserid= $_GET["userid"];
    $totalprice= $_POST["total"];

    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    mysqli_set_charset($con,"utf8");

    $sql = "select point from members where id='$orderuserid'";
    $result = mysqli_query($con, $sql);
    $row = mysqli_fetch_array($result);
    $point=  $row["point"];
    if ($point<$totalprice)
    {
      echo("
          <script>
          alert('포인트가 부족합니다.');
          location.href = 'cart.php';history.go(-1)
          </script>
      ");
    }else {
    $new_point = $row["point"] - $totalprice;
    $sql = "update members set point=$new_point where id='$orderuserid'";
    mysqli_query($con, $sql);


    $sql = "update orderlist set gubon='주문' where userid='$orderuserid' ";
    mysqli_query($con, $sql);
    mysqli_close($con);
    echo "
	     <script>
       alert('포인트로 주문하였습니다.');
        location.href = 'cart.php';
	     </script>
	   ";
}
?>
