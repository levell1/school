<?php
    session_start();


    $num   = $_GET["num"];
    $con = mysqli_connect("localhost", "user1", "12345", "sample");
    $sql = "delete from orderlist where num = $num";
    mysqli_query($con, $sql);
    mysqli_close($con);

    echo "
	     <script>
       alert('처리하였습니다.');
	         location.href = 'cart.php';
	     </script>
	   ";
?>
