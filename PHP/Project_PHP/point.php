<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/member.css">
<script type="text/javascript" src="./js/member_modify.js"></script>
</head>
<body>
	<header>
    	<?php include "header.php";?>
    </header>
<?php
   	$con = mysqli_connect("localhost", "user1", "12345", "sample");
		  mysqli_set_charset($con,"utf8");
    $sql    = "select * from members where id='$userid'";
    $result = mysqli_query($con, $sql);
    $row    = mysqli_fetch_array($result);

    $point = $row["point"];
    mysqli_close($con);
?>
	<section>
        <div id="main_content">
      		<div id="join_box">
          	<form  name="member_form" method="post" action="point_update.php?id=<?=$userid?>">
			    <h2>포인트 충전하기</h2>
    		    	<div class="form id">
				        <div class="col1">현재 포인트</div>
				        <div class="col2">
									<input type="hidden" name="point" value="<?=$point?>">
							<?=$point?>
				        </div>
			       	</div>
			       	<div class="clear"></div>

			       	<div class="bottom_line"> </div>
			       	<div class="buttons">
								<input type="text" value="0" name="chargepoint">
						<input type="submit" value="충전 하기">
						</div>
           	</form>
        </div> 
	</section>
	<footer>
    	<?php include "footer.php";?>
    </footer>
</body>
</html>
