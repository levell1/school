<?php
    session_start();

    $state= $_GET["state"];
    $num= $_GET["num"];
    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    mysqli_set_charset($con,"utf8");
    $sql = "update orderlist set state='$state' where num='$num' ";
    mysqli_query($con, $sql);
    mysqli_close($con);
    echo "
	     <script>
	         location.href = 'admin_order.php';
	     </script>
	   ";

?>
