$(document).ready(function(){
  $('#st_main_menu .menu li.expanded').not('[class*="active"]').addClass('havechild');
  $('#st_main_menu .menu li.active-trail').addClass('havechild-active');
  $('#st_main_menu .menu li.leaf').hover(
    function () {
      $(this,'a').not('[class*="active"]').addClass('sfhover');
    },
    function () {
      $(this).removeClass('sfhover');
    }
  );
  $('#st_main_menu .menu li.active-trail').hover(
    function () {
      $(this,'a').not('[class*="child"]').addClass('activesfhover');
    },
    function () {
      $(this).removeClass('activesfhover');
    }
  );
  $('#st_main_menu .menu li.havesubchild').hover(
    function() { 
      $(this).removeClass('havesubchild');
      $(this).addClass('havesubchildsfhover');
    },
    function() { 
      $(this).removeClass('havesubchildsfhover');
      $(this).addClass('havesubchild');
    }
  );
  
  $('#st_main_menu .menu li.havesubchild-active').hover(
    function() { 
      $(this).removeClass('havesubchild-active');
      $(this).addClass('havesubchild-activesfhover');
    },
    function() { 
      $(this).removeClass('havesubchild-activesfhover');
      $(this).addClass('havesubchild-active');
    }
  );
  
  $('#st_main_menu .menu li.havechild').hover(
    function() { 
      $(this).removeClass('havechild');
      $(this).addClass('havechildsfhover');
    },
    function() { 
      $(this).removeClass('havechildsfhover');
      $(this).addClass('havechild');
    }
  );
  
  $('#st_main_menu .menu li.havechild-active').hover(
    function() { 
      $(this).removeClass('havechild-active');
      $(this).addClass('havechild-activesfhover');
    },
    function() { 
      $(this).removeClass('havechild-activesfhover');
      $(this).addClass('havechild-active');
    }
  );
  
});