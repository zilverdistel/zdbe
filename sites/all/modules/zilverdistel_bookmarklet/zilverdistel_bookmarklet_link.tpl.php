Link: <a href='javascript:
var nodeaddpath="<?php echo $node_add_path; ?>",
  d=document,
  w=window,
  e=w.getSelection,
  k=d.getSelection,
  x=d.selection,
  s=e?e():k?k():x?x.createRange().text:0,
  l=d.location,
  e=encodeURIComponent,
  title=""+d.title+"",
  body=""+s+"",
  url=nodeaddpath+"&edit[title]="+e(title)+"&edit[body][und][0][value]="+e(body)+"&edit[field_original_link][und][0][url]="+l
;
console.log(e);
nourl=function() {
	w.location=nodeaddpath
}
;
a=function() {
	w.open(url,"quickpost","toolbar=0,resizable=1,scrollbars=1,status=1,width=1024,height=570")||(l.href=url)
}
;
/Firefox/.test(navigator.userAgent)?"about:blank"==l?setTimeout(nourl,0):setTimeout(a,0):"about:blank"==l?nourl():a();
;
void(0);
'>Post this!</a>
