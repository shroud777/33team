	ll l = ;
	ll r = ;
	ll ans = ;
	while(l <= r)
	{
		ll mid=(l+r)/2;
		if(mid)
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}