<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head profile="http://www.w3.org/2005/10/profile">
<link rel="icon" 
      type="image/png" 
      href="favicon.png">
<title>Neverball ME - Blog</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1"/>
<link href="style.css" rel="stylesheet" type="text/css"/>

<!-- Begin IE Fixes (Don't touch unless you know what you're doing!)-->
	<!--[if IE]>
	<link type="text/css" href="ie.css" rel="stylesheet" />
	<![endif]-->
<!-- End of IE fixes -->
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-22089475-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</head>
<body>
	<div style="top: 0; right: 0; position: fixed; ">
		<form action="https://www.paypal.com/cgi-bin/webscr" method="post">
		<input type="hidden" name="cmd" value="_s-xclick">
		<input type="hidden" name="hosted_button_id" value="TZXUP44TN8WAN">
		<input type="image" src="https://www.paypalobjects.com/WEBSCR-640-20110306-1/en_US/i/btn/btn_donate_SM.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
		<img alt="" border="0" src="https://www.paypalobjects.com/WEBSCR-640-20110306-1/en_US/i/scr/pixel.gif" width="1" height="1">
		</form>
	</div>
<div id="container">
	<div id="navigation">
		<ul>
		<li><a href="http://neverball-me.galaxyclock.com">Home</a></li>
		<li><a href="http://forum.nevercorner.net/">Forums</a></li>
		<li><a href="https://github.com/gjtorikian/Neverball-ME">Source Code</a></li>
		<li><a href="#">neverball.me [ at ] gmail [ dot ] com</a> <a href="http://www.twitter.com/neverballme"><img src="http://twitter-badges.s3.amazonaws.com/t_small-a.png" alt="Follow neverballme on Twitter"/></a></li>
		</ul>
		
	</div>
	
		<div id="header">
		  <h1>Neverball ME</h1>
		  <h2>(for Android)</h2>
		</div>
				<div id="wrapper">
				<div id="content">
				<script type="text/javascript" src="http://neverball-me.tumblr.com/js"></script>
					<a href="http://neverball-me.tumblr.com/rss" style="float:right;">RSS</a>
					<?php
					date_default_timezone_set('Americas/Los_Angeles');
					$request_url = "http://neverball-me.tumblr.com/api/read?type=text&start=0&num=10";
					$xml = simplexml_load_file($request_url);
					
					foreach ($xml->posts->post as $post)
					{
						$postID = $post['id'];
						$title = date("M jS, H:i",strtotime($post['date'])) . " EST &mdash;" . $post->{'regular-title'};
						$content = $post->{'regular-body'};
						echo '<h1>'.$title. ' ' . $postID.'</h1>';
						echo '<p>'.$content.'</p>';
						?>
						<div id="disqus_thread"></div>
						<script type="text/javascript">
						    /* * * CONFIGURATION VARIABLES: EDIT BEFORE PASTING INTO YOUR WEBPAGE * * */
						    var disqus_shortname = 'neverball-me-blog'; // required: replace example with your forum shortname

						    // The following are highly recommended additional parameters. Remove the slashes in front to use.
						    // var disqus_identifier = 'unique_dynamic_id_1234';
						    // var disqus_url = 'http://example.com/permalink-to-page.html';

						    /* * * DON'T EDIT BELOW THIS LINE * * */
						    (function() {
						        var dsq = document.createElement('script'); dsq.type = 'text/javascript'; dsq.async = true;
						        dsq.src = 'http://' + disqus_shortname + '.disqus.com/embed.js';
						        (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
						    })();
						</script>
						<noscript>Please enable JavaScript to view the <a href="http://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>
						<a href="http://disqus.com" class="dsq-brlink">blog comments powered by <span class="logo-disqus">Disqus</span></a>
						<?php
					}
					?>
					<h1>Donations</h1>
						<p>Did you like this project? Then please, consider sending a donation to support it.<br/>
						Otherwise I'll have to fill the page with ads like this one:</p>
						<center>
							<script type="text/javascript"><!--
							google_ad_client = "ca-pub-6880494445688269";
							/* Neverball-ME */
							google_ad_slot = "5561765365";
							google_ad_width = 300;
							google_ad_height = 250;
							//-->
							</script>
							<script type="text/javascript"
							src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
							</script>
						</center>
					</div>
<div id="footer">

	<span id="design-by">Original Design by <a href="http://smallpark.org">Smallpark Studios<!-- Thank you for keeping this on --></a></span> 
	  Garen J. Torikian 2011
</div>
</div>
</body>
</html>

<!-- Design by Smallpark.org. Released as open source. -->