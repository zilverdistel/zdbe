$(document).ready(function(){
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
      $(this).find('ul:first').show('slow');
      $(this).removeClass('havesubchild');
      $(this).addClass('havesubchildsfhover');
    },
    function() { 
      $(this).find('ul:first').hide('slow');
      $(this).removeClass('havesubchildsfhover');
      $(this).addClass('havesubchild');
    }
  );
  
  $('#st_main_menu .menu li.havesubchild-active').hover(
    function() { 
      $(this).find('ul:first').show('slow');
      $(this).removeClass('havesubchild-active');
      $(this).addClass('havesubchild-activesfhover');
    },
    function() { 
      $(this).find('ul:first').hide('slow');
      $(this).removeClass('havesubchild-activesfhover');
      $(this).addClass('havesubchild-active');
    }
  );
  $('#st_main_menu .menu li.havechild').hover(
    function() { 
      $(this).find('ul:first').show('slow');
      $(this).removeClass('havechild');
      $(this).addClass('havechildsfhover');
    },
    function() { 
      $(this).find('ul:first').hide("slow");
      $(this).removeClass('havechildsfhover');
      $(this).addClass('havechild');
    }
  );
  
  $('#st_main_menu .menu li.havechild-active').hover(
    function() { 
      $(this).find('ul:first').show('slow');
      $(this).removeClass('havechild-active');
      $(this).addClass('havechild-activesfhover');
    },
    function() { 
      $(this).find('ul:first').hide('slow');
      $(this).removeClass('havechild-activesfhover');
      $(this).addClass('havechild-active');
    }
  );
});