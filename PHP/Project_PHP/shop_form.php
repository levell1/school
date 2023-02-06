<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Post-IT</title>
<link rel="shortcut icon" href="./img/post-it.png"/>
<link rel="stylesheet" type="text/css" href="./css/common.css">
<link rel="stylesheet" type="text/css" href="./css/shop.css">
<script>
  function check_input() {
      if (!document.shop_form.name.value)
      {
          alert("상품명을 입력하세요!");
          document.shop_form.name.focus();
          return;
      }
      if (!document.shop_form.kind.value)
      {
          alert("종류을 입력하세요!");
          document.shop_form.kind.focus();
          return;
      }
      if (!document.shop_form.price.value)
      {
          alert("가격을 입력하세요!");
          document.shop_form.price.focus();
          return;
      }
      document.shop_form.submit();
   }
</script>
</head>
<body>
<header>
    <?php include "header.php";?>
</header>
<section>

   	<div id="shop_box">
	    <h3 id="shop_title">
	    		상품 추가
		</h3>
	    <form  name="shop_form" method="post" action="shop_insert.php" enctype="multipart/form-data">
	    	 <ul id="shop_form">

	    		<li>
	    			<span class="col1">상품명 : </span>
	    			<span class="col2"><input name="name" type="text"></span>
	    		</li>
          <li>
	    			<span class="col1">종류</span>
            <select name="kind">
              <option value="">종류선택</option>
              <option value="문구">문구</option>
              <option value="퀼트제품">퀼트제품</option>
              <option value="기타">기타</option>
            </select>
	    		</li>
          <li>
	    			<span class="col1">가격 : </span>
	    			<span class="col2"><input name="price" type="text"></span>
	    		</li>
	    		<li>
			        <span class="col1">상품이미지</span>
			        <span class="col2"><input type="file" name="upfile"></span>
			    </li>
	    	    </ul>
	    	<ul class="buttons">
				<li><button type="button" onclick="check_input()">완료</button></li>
				<li><button type="button" onclick="location.href='admin.php'">돌아가기</button></li>
			</ul>
	    </form>
	</div> 
</section>
<footer>
    <?php include "footer.php";?>
</footer>
</body>
</html>
