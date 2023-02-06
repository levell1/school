<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/admin.css">
</head>
<body>
<header>
    <?php include "header.php";?>
</header>
<section>
   	<div id="admin_box">
	    <h3 id="member_title">
	    	회원 관리
		</h3>
	    <ul id="member_list">
				<li>
					<span class="col1">번호</span>
					<span class="col2">아이디</span>
					<span class="col3">이름</span>
					<span class="col4">레벨</span>
					<span class="col5">포인트</span>
					<span class="col6">가입일</span>
					<span class="col7">수정</span>
					<span class="col8">삭제</span>
				</li>
<?php
	$con = mysqli_connect("localhost", "user1", "12345", "sample");
  mysqli_set_charset($con,"utf8");
	$sql = "select * from members order by num desc";
	$result = mysqli_query($con, $sql);
	$total_record = mysqli_num_rows($result); // 전체 회원 수

	$number = $total_record;

   while ($row = mysqli_fetch_array($result))
   {
      $num         = $row["num"];
	  $id          = $row["id"];
	  $name        = $row["name"];
	  $level       = $row["level"];
      $point       = $row["point"];
      $regist_day  = $row["regist_day"];
?>

		<li>
		<form method="post" action="admin_member_update.php?num=<?=$num?>">
			<span class="col1"><?=$number?></span>
			<span class="col2"><?=$id?></a></span>
			<span class="col3"><?=$name?></span>
			<span class="col4"><input type="text" name="level" value="<?=$level?>"></span>
			<span class="col5"><input type="text" name="point" value="<?=$point?>"></span>
			<span class="col6"><?=$regist_day?></span>
			<span class="col7"><button type="submit">수정</button></span>
			<span class="col8"><button type="button" onclick="location.href='admin_member_delete.php?num=<?=$num?>'">삭제</button></span>
		</form>
		</li>

<?php
   	   $number--;
   }
?>
	    </ul>
	    <h3 id="member_title">
	    	게시판 관리
		</h3>
	    <ul id="board_list">
		<li class="title">
			<span class="col1">선택</span>
			<span class="col2">번호</span>
			<span class="col3">이름</span>
			<span class="col4">제목</span>
			<span class="col5">첨부파일명</span>
			<span class="col6">작성일</span>
		</li>
		<form method="post" action="admin_board_delete.php">
<?php
	$sql = "select * from board order by num desc";
	$result = mysqli_query($con, $sql);
  $total_recorda = mysqli_num_rows($result);
	$numbera = $total_recorda;

   while ($row = mysqli_fetch_array($result))
   {
      $num         = $row["num"];
	  $name        = $row["name"];
	  $subject     = $row["subject"];
	  $file_name   = $row["file_name"];
      $regist_day  = $row["regist_day"];
      $regist_day  = substr($regist_day, 0, 10)
?>
		<li>
			<span class="col1"><input type="checkbox" name="item[]" value="<?=$num?>"></span>
			<span class="col2"><?=$numbera?></span>
			<span class="col3"><?=$name?></span>
			<span class="col4"><?=$subject?></span>
			<span class="col5"><?=$file_name?></span>
			<span class="col6"><?=$regist_day?></span>
		</li>
<?php
   	   $numbera--;
   }

?>
				<button type="submit">선택된 글 삭제</button>
			</form>
	    </ul>
      <h3 id="member_title">
        상품 관리
    </h3>
      <ul id="shop_list">
        <li>
          <span class="col0">번호</span>
          <span class="col1">상품 정보</span>
          <span class="col2">가격</span>
          <span class="col3">분류</span>
          <span class="col5">가격 수정</span>
          <span class="col5">삭제 </span>

        </li>

        <?php
          mysqli_set_charset($con,"utf8");
          $sql = "select * from store order by num desc";
        	$result = mysqli_query($con, $sql);
          $total_recorda = mysqli_num_rows($result);
        	$numberb = $total_recorda;

        	while( $row = mysqli_fetch_array($result) )
        	{
        		$num         = $row["num"];
        		$kind        = $row["kind"];
        		$name        = $row["name"];
        		$filename    = $row["filename"];
        		$price  = $row["price"];


        				$file_path = "data/".$filename;
        				?>
                <form method="post" name="form">
                <li>
                  <span class="col0"><?=$numberb?></span>
                  <a class="col1"><img src="<?=$file_path?>" alt="debug"> <br><?=$name?></a>
                  <span class="col2"><input style="width:100px;" type="text" name="price" value="<?=$price?>"></span>
                  <span class="col3"><?=$kind?></span>
                  <span class="col5"><button  type="submit" value="upd" onclick="javascript: form.action='admin_shop_update.php?num=<?=$num?>'">가격 수정</button></span>
                  <span class="col5"><button  type="submit" value="del" onclick="javascript: form.action='admin_shop_delete.php?num=<?=$num?>'">삭제</button>
              </span>

                </li>
              </form>
        				<?php
                $numberb--;
              }
          mysqli_close($con);
        ?>

        <button class="col1" onclick="location.href='shop_form.php'">상품 추가하기</button>

      </ul>
</div>
</section>
<footer>
    <?php include "footer.php";?>
</footer>
</body>
</html>
