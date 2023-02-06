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

    $pass = $row["pass"];
    $name = $row["name"];
		$addr = $row["addr"];
    $email = explode("@", $row["email"]);
    $email1 = $email[0];
    $email2 = $email[1];

    mysqli_close($con);
?>
	<section>
        <div id="main_content">
      		<div id="join_box">
          	<form  name="member_form" method="post" action="information.php?id=<?=$userid?>">
			    <h2>회원 정보수정</h2>
    		    	<div class="form id">
				        <div class="col1">아이디</div>
				        <div class="col2">
							<?=$userid?>
				        </div>
			       	</div>
			       	<div class="clear"></div>

			       	<div class="form">
				        <div class="col1">비밀번호</div>
				        <div class="col2">
							<input type="password" name="pass" value="<?=$pass?>">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form">
				        <div class="col1">비밀번호 확인</div>
				        <div class="col2">
							<input type="password" name="pass_confirm" value="<?=$pass?>">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form">
				        <div class="col1">이름</div>
				        <div class="col2">
							<input type="text" name="name" value="<?=$name?>">
				        </div>
			       	</div>
							<div class="form">
				        <div class="col1">주소</div>
				        <div class="col2">
							<input type="text" name="addr" value="<?=$addr?>">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form email">
				        <div class="col1">이메일</div>
				        <div class="col2">
							<input type="text" name="email1" value="<?=$email1?>">@<input
							       type="text" name="email2" value="<?=$email2?>">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="bottom_line"> </div>
			       	<div class="buttons">
										<input type="submit" value="저장하기">&nbsp;&nbsp;
										<a href="logout.php"><input type="button" value="로그아웃"></a>
	           		</div>
								<button type="button" onclick="location.href='information_del.php?id=<?=$userid?>'">회원탈퇴</button>
           	</form>
        	</div> 
        </div>
	</section>
	<footer>
    	<?php include "footer.php";?>
    </footer>
</body>
</html>
