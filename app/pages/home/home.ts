import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { DetailPage } from '../detail/detail';
import { YoutubeService } from '../../providers/youtube-service/youtube-service';
import { ServerlessService } from '../../providers/serverless-service/serverless-service';
import { Observable } from 'rxjs/Observable';
import { FORM_DIRECTIVES, FormControl } from '@angular/forms';

//Use this to switch from using youtube directly or from serveless
const useServerless = false;

@Component({
  providers: [YoutubeService, ServerlessService],
  directives: [FORM_DIRECTIVES],
  templateUrl: 'build/pages/home/home.html'

})
export class HomePage {
  videos: Observable<any[]>;
  searchInput = new FormControl();
  constructor(public navCtrl: NavController, private serverless: ServerlessService, youtube: YoutubeService) {
    const service = useServerless ? serverless : youtube;
    this.videos = service.load(this.searchInput.valueChanges
      //optionally debounce
      .debounceTime(300)
    );
  }

  itemTapped(event, video) {
    this.navCtrl.push(DetailPage, {
      video: video
    });
  }

}
