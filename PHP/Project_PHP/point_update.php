<meta charset="utf-8">
<?php

  $addpoint = $_POST["chargepoint"];
  $userid = $_GET["id"];

  $con = mysqli_connect("localhost", "user1", "12345", "sample");
  mysqli_set_charset($con,"utf8");
	$sql = "select point from members where id='$userid'";
	$result = mysqli_query($con, $sql);
	$row = mysqli_fetch_array($result);
  $point = $row["point"];
  $new_point = $point + $addpoint;

	$sql = "update members set point=$new_point where id='$userid'";
	mysqli_query($con, $sql);

	mysqli_close($con);

	echo "
	   <script>
      history.go(-1);
	   </script>
	";
?>
